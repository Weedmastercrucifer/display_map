import QtQuick 2.11
import QtQuick.Window 2.11
import QtLocation 5.11
import QtPositioning 5.8
import QtQuick.Controls 2.1
import Esri.Samples 1.0
import Esri.ArcGISRuntime.Toolkit 100.11
//import "Marker.qml"
//import "Line.qml"


Item {
    Plugin {
            id: mapPlugin
            name: "esri"
        }
    ListModel{
            id: md
        }
   Map {
           id: map
           anchors.fill: parent
           zoomLevel: 3
           plugin: mapPlugin
            center: QtPositioning.coordinate(73.8021, 15.4561)
            gesture.enabled: true


    MapItemView{
                model: md
                delegate: Marker{
                    text: title
                    coordinate: QtPositioning.coordinate(coords.latitude, coords.longitude)
                }
            }
    Line{
                id: li
            }
    MouseArea{
                id: mouseArea
                anchors.fill: parent
                z: 1
                onClicked: {
                    acceptedButtons: Qt.LeftButton | Qt.RightButton
                    if(mouse.button==Qt.LeftButton)
                    {
                    var point = Qt.point(mouse.x, mouse.y)
                    var coord = map.toCoordinate(point);
                    var text = md.count + 1;
                    md.append({"coords": coord, "title": text})
                    li.addCoordinate(coord)
                    }
                    else
                    {
                       li.pathLength()
                    }

                }
            }


}
}

