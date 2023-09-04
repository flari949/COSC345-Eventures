QT       += core gui

#DESTDIR = $$PWD/deploy

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../src/data_fetch.cpp \
    ../src/event_url.cpp \
    ../src/process_raw.cpp \
    ../src/request.cpp \
    main.cpp


HEADERS += \
    ../src/data_fetch.h \
    ../src/event_url.h \
    ../src/process_raw.h \
    ../src/request.h \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

LIBS += -L$$PWD/../include/lib -llibcurl
INCLUDEPATH += $$PWD/../include
