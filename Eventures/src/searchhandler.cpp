#include "searchhandler.h"
#include <QDebug>
#include <iostream>

// Program to define class for handling QML input values

SearchHandler::SearchHandler(QObject *parent) : QObject(parent) {}

void SearchHandler::parse(const QString &text) {
    qDebug() << "Text recieved: " << text;
    std::cout << text.toStdString() << std::endl;
}
