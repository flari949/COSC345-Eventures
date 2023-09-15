// Copyright 2023 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#include "Map_display.h"
#include <LicenseResult.h>

#include "ArcGISRuntimeEnvironment.h"
#include "MapQuickView.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>

#include <QDir>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

//------------------------------------------------------------------------------

using namespace Esri::ArcGISRuntime;

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    const QString apiKey = QString("AAPK18146ed0fc9647b584c05aade161704beAv6qom-bquOTRFR3xo7KkCI_VT-qmP5ploa0dvIj5bZ7fp1o-46L_7Ai_ffh0Gu");
    if (apiKey.isEmpty())
    {
        qWarning();
    }
    else
    {
        ArcGISRuntimeEnvironment::setApiKey(apiKey);
    }

    // Production deployment of applications built with ArcGIS Maps SDK requires you to
    // license ArcGIS Maps SDK functionality. For more information see
    // https://links.esri.com/arcgis-runtime-license-and-deploy.
    LicenseResult result = ArcGISRuntimeEnvironment::setLicense("runtimelite,1000,rud3408966572,none,ZZ0RJAY3FLGL2B3TR178");

    // Register the map view for QML
    qmlRegisterType<MapQuickView>("Esri.map_display", 1, 0, "MapView");

    // Register the Map_display (QQuickItem) for QML
    qmlRegisterType<Map_display>("Esri.map_display", 1, 0, "Map_display");

    // Initialize application view
    QQmlApplicationEngine engine;

    // Add the import Path
    engine.addImportPath(QDir(QCoreApplication::applicationDirPath()).filePath("qml"));

    // Set the source
    engine.load(QUrl("qrc:/qml/main.qml"));

    return app.exec();
}

//------------------------------------------------------------------------------
