
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

import QtQuick.Controls 2.2
import Esri.display_map 1.0
import QtQuick 2.6
import QtLocation 5.11
import QtPositioning 5.8
import QtQuick.Window 2.11
//import "DrawTransect.qml"


ApplicationWindow {

    visible: true
    width: 800
    height: 600


    ShowCallout{
        anchors.fill: parent


    }
    Loader {
            id: loaderId
            anchors.fill: parent
            source: ""
        }






    Button {
        id: button3
        x: 822
        y: 428
        width: 155
        height: 63
        text: qsTr("Edit Mission File")
    }

    Button {
        id: button
        x: 822
        y: 0
        text: qsTr("Line Following ")
        onClicked: {if(loaderId.source == "")
                loaderId.source = "DrawTransect.qml"
            else
                loaderId.source = ""}


    }











    Button {
        id: button1
        x: 822
        y: 77
        text: qsTr("Altitude Control")

    }

    Button {
        id: button2
        x: 822
        y: 160
        text: qsTr("Camera Start/Stop")
    }
}


/*##^##
Designer {
    D{i:0;formeditorZoom:0.66}
}
##^##*/
