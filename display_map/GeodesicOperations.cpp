#ifdef PCH_BUILD
#include "pch.hpp"
#endif // PCH_BUILD

#include "GeodesicOperations.h"

#include "Map.h"
#include "MapQuickView.h"
#include "GraphicsOverlay.h"
#include "Graphic.h"
#include "SimpleMarkerSymbol.h"
#include "SimpleLineSymbol.h"
#include "GeometryEngine.h"
#include "SpatialReference.h"
#include "PolylineBuilder.h"
#include "Point.h"
#include <QDebug>

using namespace Esri::ArcGISRuntime;

GeodesicOperations::GeodesicOperations(QQuickItem* parent /* = nullptr */):
  QQuickItem(parent)
{
}

void GeodesicOperations::init()
{
  // Register the map view for QML
  qmlRegisterType<MapQuickView>("Esri.Samples", 1, 0, "MapView");
  qmlRegisterType<GeodesicOperations>("Esri.Samples", 1, 0, "GeodesicOperationsSample");

}

void GeodesicOperations::componentComplete()
{
  QQuickItem::componentComplete();

  // find QML MapView component
  m_mapView = findChild<MapQuickView*>("mapView");

  // Create a map using the imagery basemap
  m_map = new Map(BasemapStyle::ArcGISImageryStandard, this);

  // Set map to map view
  m_mapView->setMap(m_map);

  // Create a GraphicsOverlay
   GraphicsOverlay* graphicsOverlay = new GraphicsOverlay(this);
   m_mapView->graphicsOverlays()->append(graphicsOverlay);

   // Create Graphic Symbols
   SimpleMarkerSymbol* markerSymbol = new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, QColor("red"), 10.0f /*size*/, this);
   SimpleLineSymbol* pathSymbol = new SimpleLineSymbol(SimpleLineSymbolStyle::Dash, QColor("yellow"), 5.0f /*width*/, this);

   // Create source graphic
   const Point nycPoint(73.8021,15.4561, SpatialReference::wgs84());
   m_nycGraphic = new Graphic(nycPoint,markerSymbol, this);
   //m_nycGraphic = new Graphic(this);
   //m_nycGraphic->setSymbol(markerSymbol);
   graphicsOverlay->graphics()->append(m_nycGraphic);

   // Create destination graphic
   m_destinationGraphic = new Graphic(this);
   m_destinationGraphic->setSymbol(markerSymbol);
   graphicsOverlay->graphics()->append(m_destinationGraphic);

   // Create path graphic
   m_pathGraphic = new Graphic(this);
   m_pathGraphic->setSymbol(pathSymbol);
   graphicsOverlay->graphics()->append(m_pathGraphic);
//   PointCollection* pointCollection = new PointCollection(SpatialReference::wgs84(), this);
//   pointCollection->addPoint(nycPoint);
   //PolylineBuilder polylineBuilder(pointCollection->spatialReference());
   PolylineBuilder* polylineBuilder=new PolylineBuilder(SpatialReference::wgs84(),this);
   //polylineBuilder->addPoint(nycPoint);

   // connect to mouse clicked signal
    connect(m_mapView, &MapQuickView::mouseClicked,  this, [ this, polylineBuilder](QMouseEvent& mouseEvent)
   //connect(m_mapView, &MapQuickView::mouseClicked, this, [this](QMouseEvent& mouseEvent)
    {

      // re-project the point to match the NYC graphic
      const Point clickedPoint = m_mapView->screenToLocation(mouseEvent.x(), mouseEvent.y());
      const Point destination = GeometryEngine::project(clickedPoint, m_nycGraphic->geometry().spatialReference());

      // update the destination graphic

      m_destinationGraphic->setGeometry(destination);



      //polylineBuilder->addPoint(m_destinationGraphic);

      // create line with start/end points
      //const QList<Point> points = {nycPoint, destination};


       polylineBuilder->addPoint(destination);

       //QList<Point> points;
     // points.append(destination);
       Polyline polyline = polylineBuilder->toPolyline();

//       const int pointCollectionSize = pointCollection->size();
//       qDebug()<< pointCollectionSize;

      // densify the path as a geodesic curve and show it with the path graphic
      constexpr double maxSegmentLength = 1.0;
      const LinearUnit unitOfMeasurement(LinearUnitId::Kilometers);
      constexpr GeodeticCurveType curveType = GeodeticCurveType::NormalSection;

//      PolylineBuilder *m_polyline_builder=new PolylineBuilder(SpatialReference(4326), this);
//      m_polyline_builder->addPoint(destination);
//      const Polyline polyline = m_polyline_builder->toPolyline();

      const Geometry pathGeometry = GeometryEngine::densifyGeodetic(polyline, maxSegmentLength, unitOfMeasurement, curveType);

      // update the graphic
      m_pathGraphic->setGeometry(pathGeometry);

      // calculate the path's geodetic length
      m_distanceText = QString::number(GeometryEngine::lengthGeodetic(pathGeometry, unitOfMeasurement, curveType), 'f', 2);
      emit distanceTextChanged();
    });
  }

//Polyline GeodesicOperations::pointsToPolyline(const QList<Point>& points) //add const
//Polyline GeodesicOperations::pointsToPolyline(PointCollection* pointCollection)
////Polyline GeodesicOperations::pointsToPolyline(const QPoint destination)
//{
//// PolylineBuilder polylineBuilder(SpatialReference::wgs84());
////for ( Point& point : point)//add const
////    polylineBuilder.addPoint(point);

//     PolylineBuilder polylineBuilder(pointCollection->spatialReference());
//     const int pointCollectionSize = pointCollection->size();
//     qDebug()<< pointCollectionSize;

//       for (int i = 0; i < pointCollectionSize; i++)
//       {
//         polylineBuilder.addPoint(pointCollection->point(i));
//       }

//  return polylineBuilder.toPolyline();
//}

QString GeodesicOperations::distanceText() const
{
  return m_distanceText;
}

/*connect(m_mapView, &MapQuickView::mouseClicked, this, [this](QMouseEvent &mouseEvent)
 * { // get click location, create point, symbolize, display as grpahic
 * const Point clickedPoint = m_mapView->screenToLocation(mouseEvent.x(), mouseEvent.y());
 * const Geometry pointGeom = GeometryEngine::normalizeCentralMeridian(clickedPoint);
 * SimpleMarkerSymbol* pointMarkerSymbol = new SimpleMarkerSymbol(SimpleMarkerSymbolStyle::Circle, QColor("red"), 10, this);
 *  m_graphicOverlay->graphics()->append(new Graphic(pointGeom, pointMarkerSymbol));
 *  // add point to polyline builder, create polyline from builder, symbolize, display polyline graphic
 * m_polylineBuilder->addPoint(pointGeom);
 * const Polyline singleLine = m_polylineBuilder->toPolyline();
 * SimpleLineSymbol* lineSymbol = new SimpleLineSymbol(SimpleLineSymbolStyle::Dash, QColor("blue"), 3, this);
 * m_graphicOverlay->graphics()->append(new Graphic(singleLine, lineSymbol));});‍‍‍‍‍‍‍‍‍‍‍‍‍‍
 */

