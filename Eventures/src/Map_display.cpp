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

#include "request.h"
#include <vector>
#include <map>
#include <string>
#include <iostream>

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

void Map_display::setupViewpoint()
{
    // Center the map on Auckland, New Zealand
    const Point center(174.76516172389003, -36.87343058062796, SpatialReference::wgs84());
    const Viewpoint viewpoint(center, 50000.0); // You can adjust the scale as needed
    m_mapView->setViewpoint(viewpoint);
}

Point Map_display::createGraphics(GraphicsOverlay *overlay)
{
    // Get event array with active parameters
    std::vector<std::map<std::string, std::string>> eventarr = get_events();

    // Get unique location coordinates & repitition count - prevents layering markers
    std::map<std::pair<std::string, std::string>, int> points;
    for (int itr=0; itr < eventarr.size(); itr++) {
        // Count point occurances - can truncate coordinate values for generalisation
        points[std::make_pair(eventarr[itr]["lat"], eventarr[itr]["lng"])] += 1;
    }

    if (points.empty()) return Point();
    double lat = 0, lng = 0;

    for (auto const& location : points) {
        lat = std::stod(location.first.first);
        lng = std::stod(location.first.second);
        // Number of events at location
//        int occurances = location.second;

        // Create a point using the event's latitude and longitude
        Point point(lng, lat, SpatialReference::wgs84());

        PictureMarkerSymbol* point_symbol = new PictureMarkerSymbol(QUrl("qrc:/qml/images/marker4.png"), this);
        point_symbol->setWidth(30);
        point_symbol->setHeight(30);

        Graphic* point_graphic = new Graphic(point, point_symbol, this);
        overlay->graphics()->append(point_graphic);
    };
    return Point(lng, lat, SpatialReference::wgs84());
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

    setupViewpoint();

    emit mapViewChanged();
}


// Pan to target coordinates
void Map_display::transition_coords(Point center)
{
    const Viewpoint newViewpoint(center, 100000.0);
    m_mapView->setViewpointAnimated(newViewpoint, 2.0f, AnimationCurve::EaseInOutCubic);
}


// Parse new search parameters to EventFinda API
void Map_display::searchHandler(const QString &text)
{
    // Update API parameters using data retrieval setter function
    std::vector<std::map<std::string, std::string>> eventarr = get_events(
        text.toStdString(), "", "", "", "" , "", "", "", false);

    // Clear existing graphical overlays
    m_mapView->graphicsOverlays()->clear();

    // Create new overlay with updated points
    GraphicsOverlay* overlay = new GraphicsOverlay(this);
    Point rep_point = createGraphics(overlay);
    m_mapView->graphicsOverlays()->append(overlay);

    transition_coords(rep_point);

    emit mapViewChanged();
}


// Change application magnification level
void Map_display::setZoom(bool magnify)
{
    double scale = m_mapView->mapScale();
    scale *= (magnify) ? 0.8 : 1.2;
    m_mapView->setViewpointScale(scale);
    emit mapViewChanged();
};




