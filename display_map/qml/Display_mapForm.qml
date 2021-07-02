
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

import QtQuick 2.6
import QtQuick.Controls 2.2
import Esri.display_map 1.0
import QtLocation 5.5
import Esri.ArcGISRuntime.Toolkit 100.11


Item {

     // Create MapQuickView here, and create its Map etc. in C++ code
    MapView {
        id: view
        anchors.fill: parent
        // set focus to enable keyboard navigation
        focus: true
       objectName: "mapView"
       clip: true
        NorthArrow {
                id: arrow
                width: 32
                height: 32
                anchors {
                    right: parent.right
                    bottom: parent.bottom
                }
                geoView: view
            }
    }



    // Declare the C++ instance which creates the map etc. and supply the view
//    Display_map {
//        id: model
//        mapView: view
//    }

//    Map {
//        id:map
//        zoomLevel: (maximumZoomLevel - minimumZoomLevel)/2
//        center {
//            // The Qt Company in Oslo
//            latitude: 15.4561
//            longitude: 73.8021
//        }

//    }

//    GeocodeModel {
//        id: geocodeModel
//        plugin: map.plugin
//        onStatusChanged: {
//            if ((status == GeocodeModel.Ready) || (status == GeocodeModel.Error))
//                map.geocodeFinished()
//        }
//        onLocationsChanged:
//        {
//            if (count == 1) {
//                map.center.latitude = get(0).coordinate.latitude
//                map.center.longitude = get(0).coordinate.longitude
//            }
//        }
//    }

//    MapItemView {
//        model: geocodeModel
//        delegate: pointDelegate
//    }







}









