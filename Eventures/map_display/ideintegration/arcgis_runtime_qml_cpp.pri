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

ESRIRUNTIME_QT_VERSION = 200.2.0
ESRIRUNTIME_QT_MAJOR_VERSION = 200
ESRIRUNTIME_QT_MINOR_VERSION = 2
ESRIRUNTIME_QT_PATCH_VERSION = 0

lessThan(QT_MAJOR_VERSION, 6) {
    error("This version of the ArcGIS Maps SDK for Qt requires at least Qt 6.5.1")
}

equals(QT_MAJOR_VERSION, 6) {
    lessThan(QT_MINOR_VERSION, 5) {
        error("This version of the ArcGIS Maps SDK for Qt requires at least Qt 6.5.1")
    }

    equals(QT_MINOR_VERSION, 5) : lessThan(QT_PATCH_VERSION, 1) {
        error("This version of the ArcGIS Maps SDK for Qt requires at least Qt 6.5.1")
    }
}

QT += gui network positioning sensors multimedia websockets

win32 {
    message("ArcGIS Maps SDK for Qt - Windows ("$$QT_ARCH")")
    PLATFORM = "windows"
}

message("Version " $$ESRIRUNTIME_QT_VERSION)

#-------------------------------------------------
# Compiler options
#-------------------------------------------------

SDK_INSTALL_DIR = "C:/Program Files/ArcGIS SDKs/Qt200.2.0/sdk"
ARCGIS_RUNTIME_IMPORT_PATH = ""

#-------------------------------------------------
#  Headers
#-------------------------------------------------

INCLUDEPATH += "$${SDK_INSTALL_DIR}/include"

!macx:!android:!ios {
  INCLUDEPATH += "$${SDK_INSTALL_DIR}/include/LocalServer"
}

#-------------------------------------------------
#  Libraries
#-------------------------------------------------

win32:{
  QMAKE_CXXFLAGS_WARN_ON -= -w44996

  CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += /FS
    QMAKE_LFLAGS += /IGNORE:4099
  }

  contains(QT_ARCH, x86_64):{
    LIBS +=  \
      -L$${SDK_INSTALL_DIR}/$${PLATFORM}/x64/bin \
      -L$${SDK_INSTALL_DIR}/$${PLATFORM}/x64/lib

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/$${PLATFORM}/x64/qml
  }
  else {
    LIBS +=  \
      -L$${SDK_INSTALL_DIR}/$${PLATFORM}/x86/bin \
      -L$${SDK_INSTALL_DIR}/$${PLATFORM}/x86/lib

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/$${PLATFORM}/x86/qml
  }

  CONFIG(debug, debug|release) {
    LIBS += \
      -lEsriCommonQtd \
      -lEsriRuntimeQtd
  } else {
    LIBS += \
      -lEsriCommonQt \
      -lEsriRuntimeQt
  }

  LIBS += \
      Ole32.lib
}

# Add plugin paths to QML_IMPORT_PATH
QML_IMPORT_PATH += $${ARCGIS_RUNTIME_IMPORT_PATH}

# Add plugin paths to QMLPATHS
QMLPATHS += $${ARCGIS_RUNTIME_IMPORT_PATH}

#----------------------------------------------------------------------------
# The following remains in place to support upgrading older templates to
# newer versions of Runtime. New templates will use the above macros instead
#----------------------------------------------------------------------------

# Set ArcGIS Runtime QML API Path
DEFINES += ARCGIS_RUNTIME_IMPORT_PATH=\"$$ARCGIS_RUNTIME_IMPORT_PATH\"
