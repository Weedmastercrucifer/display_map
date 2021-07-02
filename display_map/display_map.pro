#-------------------------------------------------
#  Copyright 2019 ESRI
#
#  All rights reserved under the copyright laws of the United States
#  and applicable international laws, treaties, and conventions.
#
#  You may freely redistribute and use this sample code, with or
#  without modification, provided you include the original copyright
#  notice and use restrictions.
#
#  See the Sample code usage restrictions document for further information.
#-------------------------------------------------

TEMPLATE = app

CONFIG += c++14
include(D:\PS1 project\arcgis-runtime-toolkit-qt-main\uitools\toolkitcpp.pri)
#enter path for arcgis runtime toolkit toolkit cpp.pri in this include statement
# additional modules are pulled in via arcgisruntime.pri
QT += opengl qml quick

TARGET = display_map

equals(QT_MAJOR_VERSION, 5) {
    lessThan(QT_MINOR_VERSION, 15) { 
        error("$$TARGET requires Qt 5.15.1")
    }
	equals(QT_MINOR_VERSION, 15) : lessThan(QT_PATCH_VERSION, 1) {
		error("$$TARGET requires Qt 5.15.1")
	}
}

equals(QT_MAJOR_VERSION, 6) {
  error("This version of the ArcGIS Runtime SDK for Qt is incompatible with Qt 6")
}

ARCGIS_RUNTIME_VERSION = 100.11
include($$PWD/arcgisruntime.pri)

HEADERS += \
    Display_map.h \
    ShowCallout.h

SOURCES += \
    ShowCallout.cpp \
    main.cpp \
    Display_map.cpp

RESOURCES += \
    qml/qml.qrc \
    Resources/Resources.qrc

#-------------------------------------------------------------------------------

win32 {
    include (Win/Win.pri)
}

macx {
    include (Mac/Mac.pri)
}

ios {
    include (iOS/iOS.pri)
}

android {
    include (Android/Android.pri)
}
