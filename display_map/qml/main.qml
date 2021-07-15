
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

import QtQuick.Controls 2.3
import Esri.display_map 1.0
import QtQuick 2.6
import QtLocation 5.11
import QtPositioning 5.8
import QtQuick.Window 2.11
//import "DrawTransect.qml"


ApplicationWindow {

    visible: true
    title: qsTr("Mission Planner")
    width: 1000
    height: 1000


    ShowCallout{
        anchors.fill: parent
        }
    Loader {
        id: loaderId
        anchors.fill: parent
        source: ""

    }







    menuBar: MenuBar {
        Menu{
            title: qsTr("&Controls")
            MenuItem{
                text:qsTr("&Line Following")
                onTriggered: {if(loaderId.source == "")
                        loaderId.source = "GeodesicOperations.qml"
                    else
                        loaderId.source = ""}

            }
            MenuItem{
                text:qsTr("&Altitude Control")

            }

            MenuItem{
                text:qsTr("&Camera Start/Stop")

            }

            MenuItem{
                text:qsTr("&Edit Mission File")

            }

            MenuSeparator { }
            MenuItem{
                text:qsTr("&Quit Mission Planner")
                onTriggered: Qt.quit()

            }



        }

    }
}





/*##^##
Designer {
    D{i:0;formeditorZoom:0.33}
}
##^##*/
