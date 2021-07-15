#ifndef GEODESICOPERATIONS_H
#define GEODESICOPERATIONS_H
namespace Esri
{
namespace ArcGISRuntime
{
class Map;
class MapQuickView;
class Graphic;
}
}

#include "Point.h"
#include "Polyline.h"
#include "Part.h"
#include "PointCollection.h"
#include <QQuickItem>

class GeodesicOperations : public QQuickItem
{
  Q_OBJECT

  Q_PROPERTY(QString distanceText READ distanceText NOTIFY distanceTextChanged)

public:
  explicit GeodesicOperations(QQuickItem* parent = nullptr);
  ~GeodesicOperations() override = default;

  void componentComplete() override;
  static void init();

signals:
  void distanceTextChanged();

private:
  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
  Esri::ArcGISRuntime::Graphic* m_nycGraphic = nullptr;
  Esri::ArcGISRuntime::Graphic* m_pathGraphic = nullptr;
  Esri::ArcGISRuntime::Graphic* m_destinationGraphic = nullptr;
  QString m_distanceText;

private:
  //Esri::ArcGISRuntime::Polyline pointsToPolyline(const QList<Esri::ArcGISRuntime::Point>& points);
  //Esri::ArcGISRuntime::Part
  Esri::ArcGISRuntime::Polyline pointsToPolyline(Esri::ArcGISRuntime::PointCollection* pointCollection);
  Esri::ArcGISRuntime::PointCollection* createPointCollection();
  //Esri::ArcGISRuntime::Polyline pointsToPolyline(const QPoint destination);
  // add const
  QString distanceText() const;
};

#endif // GEODESICOPERATIONS_H
