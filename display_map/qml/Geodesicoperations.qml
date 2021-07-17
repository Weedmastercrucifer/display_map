import QtQuick 2.6
import QtQuick.Controls 2.2
import Esri.Samples 1.0
import Esri.display_map 1.0
import Esri.ArcGISRuntime.Toolkit 100.11

GeodesicOperationsSample {
    id: rootRectangle
    clip: true
    width: 800
    height: 600


    // add a mapView component


    MapView {
        id:mapView
        anchors.fill: parent
        objectName: "mapView"




         Callout {
            id: callout
            calloutData: mapView.calloutData // bind to the property that is exposed
            accessoryButtonHidden: true
            leaderPosition: leaderPositionEnum.Automatic

        }





    }








    // display text for geodesic length
//    Text {
////        anchors {
////            left: parent.left
////            top: parent.top
////            margins: 10
////        }

//        text: "%1 kilometers".arg(distanceText)
//        visible: distanceText.length > 0
//        font.pixelSize: 40
//        color: "white"


//    }

    TextField {
        id: textField
        anchors {
            left: parent.left
            top: parent.top
            margins: 10
        }

        enabled: false
        placeholderText: Text

        Text {
            text: "%1 kilometers".arg(distanceText)
            visible: distanceText.length > 0
            width: textField.width
            height: textField.height
            font.pixelSize: 30
            fontSizeMode: Text.Fit

             color: "black"

        }
    }
}

