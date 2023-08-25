QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app

SOURCES +=  UnitTests.cpp

HEADERS += ../Eventures/src/event_url.h # \
    #../Eventures/src/process_raw.h \
    #../Eventures/src/data_fetch.h

SOURCES += ../Eventures/src/event_url.cpp # \
    # ../Eventures/src/process_raw.cpp \
    #../Eventures/src/data_fetch.cpp
