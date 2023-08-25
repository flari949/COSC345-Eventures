#!/bin/sh
PATH=/C/Qt/6.5.2/mingw_64/bin:$PATH
export PATH
QT_PLUGIN_PATH=/C/Qt/6.5.2/mingw_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
