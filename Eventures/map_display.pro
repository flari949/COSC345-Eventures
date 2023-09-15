#-------------------------------------------------
#  Copyright 2023 ESRI
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

CONFIG += c++17

# additional modules are pulled in via arcgisruntime.pri
QT += qml quick quickcontrols2

#TARGET = map_display

lessThan(QT_MAJOR_VERSION, 6) {
    error("$$TARGET requires Qt 6.5.1")
}

equals(QT_MAJOR_VERSION, 6) {
    lessThan(QT_MINOR_VERSION, 5) {
        error("$$TARGET requires Qt 6.5.1")
    }
	equals(QT_MINOR_VERSION, 5) : lessThan(QT_PATCH_VERSION, 1) {
		error("$$TARGET requires Qt 6.5.1")
	}
}

ARCGIS_RUNTIME_VERSION = 200.2.0
include($$PWD/include/arcgisruntime.pri)
INCLUDEPATH += \
    $$PWD/src \
    $$PWD/include

HEADERS += \
    src/Map_display.h \
    src/data_fetch.h \
    src/event_url.h \
    src/process_raw.h \
    src/request.h

SOURCES += \
    src/data_fetch.cpp \
    src/event_url.cpp \
    src/process_raw.cpp \
    src/request.cpp \
    src/main.cpp \
    src/Map_display.cpp

RESOURCES += \
    qml/qml.qrc \

# Windows Version
LIBS += \
    Ole32.lib \
    -L$$PWD/include/lib -llibcurl

# Lukes Version
#LIBS += \
##    Ole32.lib \
#    -L/Users/lukepiper/anaconda3/lib -lcurl

FORMS +=


#macx: LIBS += -L$$PWD/include/lib/ -lcurl

#INCLUDEPATH += $$PWD/include
#DEPENDPATH += $$PWD/include

#macx: PRE_TARGETDEPS += $$PWD/include/lib/libcurl.a
