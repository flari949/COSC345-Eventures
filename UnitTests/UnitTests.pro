QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

HEADERS += \
    src/data_fetch.h \
    src/event_url.h \
    src/process_raw.h

SOURCES += \
    src/data_fetch.cpp \
    src/process_raw.cpp \
    UnitTests.cpp \
    src/event_url.cpp

LIBS += -L$$PWD/lib -llibcurl
INCLUDEPATH += $$PWD/include
