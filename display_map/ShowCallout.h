#ifndef SHOWCALLOUT_H
#define SHOWCALLOUT_H
namespace Esri
{
  namespace ArcGISRuntime
  {
    class Map;
    class MapQuickView;
  }
}

#include <QQuickItem>

class ShowCallout : public QQuickItem
{
  Q_OBJECT

public:
  explicit ShowCallout(QQuickItem* parent = nullptr);
  ~ShowCallout() override;

  void componentComplete() override;
  static void init();

private:
  Esri::ArcGISRuntime::Map* m_map = nullptr;
  Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;
};


#endif // SHOWCALLOUT_H
