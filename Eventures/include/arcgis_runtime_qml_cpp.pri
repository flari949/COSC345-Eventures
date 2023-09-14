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

macx: {
    ARCH = $$QMAKE_HOST.arch
    !equals(QMAKE_APPLE_DEVICE_ARCHS, ""):{
        ARCH = $$QMAKE_APPLE_DEVICE_ARCHS
    }
    message("ArcGIS Maps SDK for Qt - Mac ("$$ARCH")")
    PLATFORM = "macOS"
}

unix:!macx:!android:!ios {
    message("ArcGIS Maps SDK for Qt - Linux ("$$QT_ARCH")")
    PLATFORM = "linux"
}

win32 {
    message("ArcGIS Maps SDK for Qt - Windows ("$$QT_ARCH")")
    PLATFORM = "windows"
}

message("Version " $$ESRIRUNTIME_QT_VERSION)

#-------------------------------------------------
# Compiler options
#-------------------------------------------------

SDK_INSTALL_DIR = "C:/Program Files/ArcGIS SDKs/Qt200.2.0"
#SDK_INSTALL_DIR = "/Users/lukepiper/ArcGIS_SDKs/Qt200.2.0"
ARCGIS_RUNTIME_IMPORT_PATH = ""

unix:!macx:!android:!ios {
    eval(QMAKE_TARGET.arch = ""):{
        # QMAKE_TARGET.arch isn't set properly on Linux.
        # If we get a bitset-specific mkspec, use it
        linux-g++-32:QMAKE_TARGET.arch = x86
        linux-g++-64:QMAKE_TARGET.arch = x86_64

        # If we get a generic one, then determine the
        # arch of the machine and assign
        linux-g++:{
            ARCH = $$system(uname -m) # i686 or x86_64
            contains(ARCH, x86_64):{
                QMAKE_TARGET.arch = x86_64
            }
            else{
                QMAKE_TARGET.arch = x86
            }
        } # linux-g++
    } # eval
} # unix

macx {
    QMAKE_MACOSX_DEPLOYMENT_TARGET = 11.0

    QMAKE_POST_LINK  += install_name_tool -change libEsriCommonQt.dylib \"$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/universal/lib/libEsriCommonQt.dylib\" $${TARGET}.app/Contents/MacOS/$${TARGET} $$escape_expand(\n\t)
    QMAKE_POST_LINK  += install_name_tool -change libruntimecore.dylib \"$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/universal/lib/libruntimecore.dylib\" $${TARGET}.app/Contents/MacOS/$${TARGET} $$escape_expand(\n\t)
}

#-------------------------------------------------
#  Headers
#-------------------------------------------------

INCLUDEPATH += "$${SDK_INSTALL_DIR}/sdk/include"

!macx:!android:!ios {
  INCLUDEPATH += "$${SDK_INSTALL_DIR}/sdk/include/LocalServer"
}

#-------------------------------------------------
#  Libraries
#-------------------------------------------------

contains(QMAKE_TARGET.arch, x86):{
  unix:!macx:!android:!ios {
    LIBS += \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x86/lib \
      -lEsriRuntimeQt \
      -lEsriCommonQt \
      -lruntimecore

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x86/qml
  }
}
else {
  unix:!macx:!android:!ios {
    LIBS += \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x64/lib \
      -lEsriRuntimeQt \
      -lEsriCommonQt \
      -lruntimecore

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x64/qml
  }
}

macx:{
  LIBS += \
    -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/universal/lib \
    -lEsriCommonQt \
    -lEsriRuntimeQt

  ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/universal/qml
}

win32:{
  QMAKE_CXXFLAGS_WARN_ON -= -w44996

  CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += /FS
    QMAKE_LFLAGS += /IGNORE:4099
  }

  contains(QT_ARCH, x86_64):{
    LIBS +=  \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x64/bin \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x64/lib

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x64/qml
  }
  else {
    LIBS +=  \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x86/bin \
      -L$${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x86/lib

    ARCGIS_RUNTIME_IMPORT_PATH = $${SDK_INSTALL_DIR}/sdk/$${PLATFORM}/x86/qml
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

# DEFINES
unix:!macx:!ios {
    contains(QMAKE_HOST.os, Linux):{
      # on some linux platforms the string 'linux' is replaced with 1
      # temporarily replace it with ARCGISRUNTIME_SDK_LINUX_REPLACEMENT
      LINUX_PLATFORM_REPLACEMENT = ARCGISRUNTIME_SDK_LINUX_REPLACEMENT

      ARCGIS_RUNTIME_IMPORT_PATH = $$replace(ARCGIS_RUNTIME_IMPORT_PATH, linux, $$LINUX_PLATFORM_REPLACEMENT)

      DEFINES += LINUX_PLATFORM_REPLACEMENT=$$LINUX_PLATFORM_REPLACEMENT
    }
}

# Set ArcGIS Runtime QML API Path
DEFINES += ARCGIS_RUNTIME_IMPORT_PATH=\"$$ARCGIS_RUNTIME_IMPORT_PATH\"
