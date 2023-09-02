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
    // Point takes coords as (East, South) --> opposite of natural order
    const Point center(173.07275377115386, -41.35249807015349, SpatialReference::wgs84());
    const Viewpoint viewpoint(center, 12000000.0);
    m_mapView->setViewpoint(viewpoint);
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

    setupViewpoint();

    emit mapViewChanged();
}
