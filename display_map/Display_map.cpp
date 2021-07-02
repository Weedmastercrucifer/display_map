
// Copyright 2019 ESRI
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

#include "Display_map.h"
#include"ArcGISRuntimeEnvironment.h"
#include "Basemap.h"
#include "Map.h"
#include "MapQuickView.h"
#include "GraphicsOverlay.h"
#include "PolylineBuilder.h"
#include "PolygonBuilder.h"
#include "SimpleMarkerSymbol.h"
#include "MapGraphicsView.h"

#include "SimpleFillSymbol.h"
#include <QUrl>

using namespace Esri::ArcGISRuntime;

Display_map::Display_map(QObject* parent /* = nullptr */):
    QObject(parent),
    m_map(new Map(BasemapStyle::ArcGISTopographic, this))
{
}

Display_map::~Display_map()
{
}

MapQuickView* Display_map::mapView() const
{
    return m_mapView;
}
void Display_map::setupMap()
{
    const Point center(73.8021, 15.4561, SpatialReference::wgs84());
    const Viewpoint viewpoint(center,100000.0);
    m_mapView->setViewpoint(viewpoint);

}

// Set the view (created in QML)
void Display_map::setMapView(MapQuickView* mapView)
{
    if (!mapView || mapView == m_mapView)
    {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);


    setupMap();
    GraphicsOverlay* overlay = new GraphicsOverlay(this);
    createGraphics(overlay);
    m_mapView->graphicsOverlays()->append(overlay);
    emit mapViewChanged();
}
void Display_map::createGraphics(GraphicsOverlay* overlay)
{

    //Point dume_beach(m_mapView->screenToLocation(mouseEvent.x(), mouseEvent.y()));
    const Point dume_beach(-118.80657463861, 34.0005930608889, SpatialReference::wgs84());
    SimpleLineSymbol* point_outline=new SimpleLineSymbol(SimpleLineSymbolStyle::Solid, QColor(Qt::blue), 3, this);
    SimpleMarkerSymbol* point_symbol=new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, QColor(Qt::red), 10, this);
    point_symbol->setOutline(point_outline);

    //Creating a graphic to display the point
    Graphic* point_graphic=new Graphic(dume_beach,point_symbol,this);
    //Adding points graphic to graphic overlay
    overlay->graphics()->append(point_graphic);

    // Creating a line

    PolylineBuilder* polyline_builder=new PolylineBuilder(SpatialReference::wgs84(),this);
    polyline_builder->addPoint(73.8021, 15.4561);
    polyline_builder->addPoint(73.7896, 15.3969);
    polyline_builder->addPoint(73.7700,15.3800);
    SimpleLineSymbol* line_symbol=new SimpleLineSymbol(SimpleLineSymbolStyle::LongDash,QColor(Qt::green),3,this);
    Graphic* polyline_graphic=new Graphic(polyline_builder->toGeometry(),line_symbol,this);
    overlay->graphics()->append(polyline_graphic);

    // Creating a polygon


}
//void Display_map::Draw_Map(MapGraphicsView* map_control)
//{

//std::shared_ptr<GraphicsOverlay> layer_geometries;

//std::shared_ptr<PolylineBuilder> polyline_tracks;

//std::shared_ptr<SimpleLineSymbol> polyline_pen;

//std::shared_ptr<Graphic> polyline_graphic;

//// choose your line style

//polyline_pen = std::make_shared<SimpleLineSymbol>(SimpleLineSymbolStyle::Dot, QColor(0, 0, 255, 100), 5);

//map_control = new MapGraphicsView(this);

//layer_geometries = std::make_shared<GraphicsOverlay>();

//map_control->graphicsOverlays()->append(p->layer_geometries.get());

//connect(m_mapView, &MapGraphicsView::mouseClicked, this, [=](QMouseEvent& e)

//{

//Point clicked_location = map_control->screenToLocation(e.x(), e.y());
//polyline_tracks->addPoint(clicked_location );

//std::shared_ptr<PolylineBuilder>close_points(p->gps_tracks);

//close_points->addPoint(p->gps_tracks->parts()->part(0)->startPoint());

//polyline_graphic= std::make_shared<Graphic>(close_points->toGeometry(), polyline_pen.get());

//layer_geometries->graphics()->clear();

//layer_geometries->graphics()->append(p->polyline_graphic.get());

//});
//}
