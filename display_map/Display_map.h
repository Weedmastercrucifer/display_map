
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

#ifndef DISPLAY_MAP_H
#define DISPLAY_MAP_H

namespace Esri
{
namespace ArcGISRuntime
{
class Map;
class MapQuickView;
class GraphicsOverlay;
class MapGraphicsView;

}
}



#include <QObject>


class Display_map : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView* mapView READ mapView WRITE setMapView NOTIFY mapViewChanged)

public:
    explicit Display_map(QObject* parent = nullptr);
    ~Display_map() override;

signals:
    void mapViewChanged();


private:
    Esri::ArcGISRuntime::MapQuickView* mapView() const;
    void setMapView(Esri::ArcGISRuntime::MapQuickView* mapView);
    void setupMap();
    void setupRouteTask();
    void findRoute();
    void resetState();
    Q_INVOKABLE void createGraphics(Esri::ArcGISRuntime::GraphicsOverlay* overlay);
    //void Draw_Map(Esri::ArcGISRuntime::MapGraphicsView* map_control);
    Esri::ArcGISRuntime::Map* m_map = nullptr;
    Esri::ArcGISRuntime::MapQuickView* m_mapView = nullptr;

};



#endif // DISPLAY_MAP_H
