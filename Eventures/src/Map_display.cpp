// Copyright 2023 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "Map_display.h"

#include "Map.h"
#include "MapTypes.h"
#include "MapQuickView.h"
#include "MapViewTypes.h"

#include "Point.h"
#include "Viewpoint.h"
#include "SpatialReference.h"
#include "TaskWatcher.h"

#include "Graphic.h"
#include "GraphicListModel.h"
#include "GraphicsOverlay.h"
#include "GraphicsOverlayListModel.h"
#include "PictureMarkerSymbol.h"
#include "Geometry.h"

#include "SimpleMarkerSymbol.h"
#include "TextSymbol.h"
#include "SymbolTypes.h"

#include "request.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>
#include <QMouseEvent>
#include <QUuid>
#include "TaskWatcher.h"
#include "IdentifyGraphicsOverlayResult.h"
#include "CoordinateFormatter.h"

using namespace Esri::ArcGISRuntime;

Map_display::Map_display(QObject* parent /* = nullptr */):
    QObject(parent),
    m_map(new Map(BasemapStyle::ArcGISTopographic, this))
{
}


Map_display::~Map_display()
{
}


MapQuickView* Map_display::mapView() const
{
    return m_mapView;
}


// Set up a basic default map view
void Map_display::setupViewpoint()
{
    // Center the map on Wellington, New Zealand
    const Point center(173.0728,-41.3564, SpatialReference::wgs84());
    const Viewpoint viewpoint(center, 12000000.0);
    m_mapView->setViewpoint(viewpoint);
}


void Map_display::createGraphics(GraphicsOverlay *overlay)
{
    // Get event array with active parameters
    std::vector<std::map<std::string, std::string>> eventarr = get_events();
    Map_display::results += static_cast<int>(eventarr.size());
    Map_display::eventInfo.clear();


    // Get unique location coordinates & repetition count - prevents layering markers
    std::map<std::pair<std::string, std::string>, int> points;
    std::vector<std::vector<std::string>> dataStrings;
    dataStrings.resize(5);

    for (int itr = 0; itr < eventarr.size(); itr++) {
        dataStrings[0].push_back(eventarr[itr]["name"]);
        dataStrings[1].push_back(eventarr[itr]["description"]);
        dataStrings[2].push_back(eventarr[itr]["url"]);
        dataStrings[3].push_back(eventarr[itr]["datetime_start"]);
        dataStrings[4].push_back(eventarr[itr]["location_summary"]);

        // Count point occurrences - can truncate coordinate values for generalization
        points[std::make_pair(eventarr[itr]["lat"], eventarr[itr]["lng"])] += 1;
    }

    if (points.empty()) return;
    Map_display::activePoints.clear();
    Map_display::eventInfo.resize(5);
    for (int itr = 0; itr < 5; itr++) {
        Map_display::eventInfo[itr].resize(static_cast<int>(points.size()));
    }

    int index = 0;
    int eventptr = 0;
    for (auto const& location : points) {
        double lat = std::stod(location.first.first);
        double lng = std::stod(location.first.second);

        // Number of events at location
        int occurrences = location.second;
        for (int itr = 0; itr < occurrences; itr++) {
            for (int i = 0; i < 5; i++) {
                Map_display::eventInfo[i][index].push_back(dataStrings[i][eventptr]);
            }
            eventptr += 1;
        }

        // Create a point using the event's latitude and longitude
        Point point(lng, lat, SpatialReference::wgs84());

        PictureMarkerSymbol* point_symbol = new PictureMarkerSymbol(QUrl("qrc:/qml/images/marker4.png"), this);
        point_symbol->setWidth(30);
        point_symbol->setHeight(30);

        // GraphicsOverlay for circle and text graphics, to display the number of events at a certain location
        GraphicsOverlay* combinedOverlay = overlay;
        Graphic* point_graphic = new Graphic(point, point_symbol, this);
        point_graphic->setProperty("id", index++);
        combinedOverlay->graphics()->append(point_graphic);

        if (occurrences > 1){
            TextSymbol* textSymbol = new TextSymbol(this);
            textSymbol->setText(QString::number(occurrences));
            textSymbol->setColor(QColor(0, 0, 0));
            textSymbol->setOffsetY(-30);
            textSymbol->setFontWeight(FontWeight::Bold);
            Graphic* textGraphic = new Graphic(point, textSymbol, this);

            SimpleMarkerSymbol* circleSymbol = new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, QColor("white"), 20, this);
            circleSymbol->setOffsetY(-30);
            Graphic* circleGraphic = new Graphic(point, circleSymbol, this);

            // Add both the circle and text graphics to the combined overlay
            combinedOverlay->graphics()->append(circleGraphic);
            combinedOverlay->graphics()->append(textGraphic);
        }
        Map_display::activePoints.push_back(point);
    }

    return;
}


// Set the view (created in QML)
void Map_display::setMapView(MapQuickView* mapView)
{
    if (!mapView || mapView == m_mapView)
    {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);

    GraphicsOverlay* overlay = new GraphicsOverlay(this);
    createGraphics(overlay);
    m_mapView->graphicsOverlays()->append(overlay);

    connectSignals();

    setupViewpoint();

    emit mapViewChanged();
}


// Pan to target coordinates
void Map_display::transition_coords(Point center)
{
    const Viewpoint newViewpoint(center, 100000.0);
    m_mapView->setViewpointAnimated(newViewpoint, 1.5f, AnimationCurve::EaseInOutCubic);
}


// Parse new search parameters to EventFinda API
void Map_display::searchHandler(const QString &text, int page)
{
    // If to page to previous, decrement result counter appropriately
    int rem = Map_display::results%20;
    int currpage = ((Map_display::results-rem)/20)-1;
    if (rem == 0) rem = 20;
    if (page < currpage){
        Map_display::results -= (20 + rem);
    }

    int offset = page * 20;
    if (page == 0) {
        Map_display::results = 0;
    }
    // Update API parameters using data retrieval URL setter function
    get_events(text.toStdString(), "", "", "", "" , "", "20", std::to_string(offset), false);

    // Clear existing graphical overlays
    m_mapView->graphicsOverlays()->clear();

    // Create new overlay with updated points
    GraphicsOverlay* overlay = new GraphicsOverlay(this);
    createGraphics(overlay);
    m_mapView->graphicsOverlays()->append(overlay);

    // Auto invoke find function
//    transition_coords(Map_display::activePoints[0]);

    emit mapViewChanged();
}


// Change application magnification level (20% inc/decriments)
void Map_display::setZoom(bool magnify)
{
    double scale = m_mapView->mapScale();
    scale *= (magnify) ? 0.8 : 1.2;
    m_mapView->setViewpointScale(scale);

    emit mapViewChanged();
};


// Find most recent (active) point
void Map_display::findPoint()
{
    transition_coords(Map_display::activePoints[Map_display::currIndex]);
    emit mapViewChanged();
}


// Switch between marker views
void Map_display::switchViews(bool next)
{
    int index = Map_display::currIndex;
    index += (next) ? 1 : -1;

    int len = static_cast<int>(Map_display::activePoints.size())-1;

    index = (index>len) ? 0 : (index<0) ? len : index;
    transition_coords(Map_display::activePoints[index]);

    Map_display::currIndex = index;
    showInfo(0);

    emit mapViewChanged();
}


// Format requested index
int Map_display::formatSubIndex(int i)
{
    int numItems = static_cast<int>(Map_display::eventInfo[0][Map_display::currIndex].size());
    while (i < 0) i += numItems;
    if (numItems > 0){
        if (i >= numItems) i = i % numItems;
    }
    return i;
}


// Get event title
QString Map_display::getTitle(int subIndex)
{
    int index = Map_display::currIndex;
    subIndex = formatSubIndex(subIndex);
    return QString::fromStdString(Map_display::eventInfo[0][index][subIndex]);
}


// Display event info box
void Map_display::showInfo(int subIndex)
{
    int index = Map_display::currIndex;
    subIndex = formatSubIndex(subIndex);
    m_eventInformation = QString::fromStdString(Map_display::eventInfo[1][index][subIndex]);
    emit eventInfoChanged();
}


// Get event URL
QString Map_display::getUrl(int subIndex)
{
    int index = Map_display::currIndex;
    subIndex = formatSubIndex(subIndex);
    return QString::fromStdString(Map_display::eventInfo[2][index][subIndex]);
}


// Get event date
QString Map_display::getDate(int subIndex)
{
    int index = Map_display::currIndex;
    subIndex = formatSubIndex(subIndex);
    return QString::fromStdString(Map_display::eventInfo[3][index][subIndex]);
}


// Get event date
QString Map_display::getLocation(int subIndex)
{
    int index = Map_display::currIndex;
    subIndex = formatSubIndex(subIndex);
    return QString::fromStdString(Map_display::eventInfo[4][index][subIndex]);
}


// Handle event marker click event - Update to show event data
void Map_display::connectSignals()
{
    connect(m_mapView, &MapQuickView::mouseClicked, this, [this](QMouseEvent& mouseEvent){
        constexpr double tolerance = 5.0;
        constexpr int max = 1;
        GraphicsOverlay* m_graphicsOverlay = m_mapView->graphicsOverlays()->first();
        m_mapView->identifyGraphicsOverlay(m_graphicsOverlay, mouseEvent.position().x(), mouseEvent.position().y(), tolerance, false, max);
    });

    connect(m_mapView, &MapQuickView::identifyGraphicsOverlayCompleted, this, [this](const QUuid&, IdentifyGraphicsOverlayResult* rawIdentifyResult)
    {
        auto identifyResult = std::unique_ptr<IdentifyGraphicsOverlayResult>(rawIdentifyResult);
        if (identifyResult && !identifyResult->graphics().empty()) {
            Esri::ArcGISRuntime::Graphic* clickedGraphic = identifyResult->graphics().at(0);
            int pointID = clickedGraphic->property("id").toInt();
            Map_display::currIndex = pointID;
            transition_coords(Map_display::activePoints[pointID]);

            // shows the event information, and ensures the qml is visible on click
            showInfo(0);
            setTicketVisible(true);

        }
    });
}

bool Map_display::isTicketVisible() const
{
    return m_ticketVisible;
}

void Map_display::setTicketVisible(bool visible)
{
    if (m_ticketVisible != visible) {
      m_ticketVisible = visible;
      emit ticketVisibleChanged(visible);

    }
}


// Check neighbouring pages populated
int Map_display::checkPage(bool next) {
    int rem = Map_display::results % 20;
    int page = ((Map_display::results - rem) /20)-1;
    if (page <= -1) page = 0;

    if (next) {
        // If current page full (following page can exist)
        if (Map_display::results % 20 == 0) {
            get_events("", "|", "", "", "" , "", "1", std::to_string((page+1)*20), false);
            int nextPageSize = static_cast<int>(get_events().size());
            // Reset params
            get_events("", "", "", "", "" , "", "20", std::to_string((page)*20), false);
            // If following page exists
            if (nextPageSize >= 1) {
                return page+1;
            }
        }
    } else {
        // If previous page exists
        if (page > 0) {
            return page-1;
        }
    }
    // If page does not exist
    return -1;
}


// Get coordinates at the centre of the map - Maintains search parameter
void Map_display::mapCentre() {
    Point center = m_mapView->screenToLocation(m_mapView->width()/2, m_mapView->height()/2);
    std::string coords = Esri::ArcGISRuntime::CoordinateFormatter::toLatitudeLongitude(
                             center, Esri::ArcGISRuntime::LatitudeLongitudeFormat::DecimalDegrees, 4).toStdString();
    std::string lat = coords.substr(0,7);
    std::string lng = coords.substr(9,8);
    if (coords[7] == 'S') lat = "-" + lat;
    if (coords[17] == 'W') lng = "-" + lng;

    // Update API parameters using data retrieval URL setter function
    get_events("", "", lat + "," + lng, std::to_string(m_mapView->mapScale()/11000), "" , "", "20", "", false);
    searchHandler("", 0);
}





