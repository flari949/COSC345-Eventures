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

#include "Point.h"
#include "Viewpoint.h"
#include "SpatialReference.h"
#include "TaskWatcher.h"

#include "Graphic.h"
#include "GraphicListModel.h"
#include "GraphicsOverlay.h"
#include "GraphicsOverlayListModel.h"
#include "PolylineBuilder.h"
#include "PolygonBuilder.h"
#include "SimpleFillSymbol.h"
#include "SimpleLineSymbol.h"
#include "PictureMarkerSymbol.h"
#include "SimpleMarkerSymbol.h"
#include "SymbolTypes.h"
#include "GeometryEngine.h"

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
    // Center the map on Wellington, New Zealand
    const Point center(174.76516172389003, -36.87343058062796, SpatialReference::wgs84());
    const Viewpoint viewpoint(center, 50000.0); // You can adjust the scale as needed
    m_mapView->setViewpoint(viewpoint);
}

void Map_display::createGraphics(GraphicsOverlay *overlay)
{
    // Get event array
    std::vector<std::map<std::string, std::string>> eventarr = get_events();

    for (const std::map<std::string, std::string>& event : eventarr) {
        auto latIter = event.find("lat");
        auto lngIter = event.find("lng");

        if (latIter != event.end() && lngIter != event.end()) {
            double lat = std::stod(latIter->second);
            double lng = std::stod(lngIter->second);

            // Create a point using the event's latitude and longitude
            Point point(lng, lat, SpatialReference::wgs84());

            PictureMarkerSymbol* point_symbol = new PictureMarkerSymbol(QUrl("qrc:/qml/images/marker4.png"), this);
            point_symbol->setWidth(30);
            point_symbol->setHeight(30);

            Graphic* point_graphic = new Graphic(point, point_symbol, this);
            overlay->graphics()->append(point_graphic);
        }
    }
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

