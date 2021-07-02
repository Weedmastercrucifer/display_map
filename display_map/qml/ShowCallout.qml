import QtQuick 2.6
import Esri.Samples 1.0
import Esri.ArcGISRuntime.Toolkit 100.11
Item {


ShowCalloutSample {
    id: showCalloutSample
    clip: true
    width: 800
    height: 600

    // add a mapView component
    MapView {
        id: mapView
        anchors.fill: parent
        objectName: "mapView"
        clip: true

        //! [set callout data]
        Callout {
            id: callout
            calloutData: mapView.calloutData // bind to the property that is exposed
            accessoryButtonHidden: true
            leaderPosition: leaderPositionEnum.Automatic
        }
        //! [set callout data]
    }
}
}
