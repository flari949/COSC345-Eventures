QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    ../Eventures/src/data_fetch.h \
    ../Eventures/src/event_url.h \
    ../Eventures/src/process_raw.h

SOURCES += \
    ../Eventures/src/data_fetch.cpp \
    ../Eventures/src/process_raw.cpp \
    UnitTests.cpp \
    ../Eventures/src/event_url.cpp

LIBS += -L$$PWD/lib -llibcurl
INCLUDEPATH += $$PWD/include
