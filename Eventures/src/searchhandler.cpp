#include "searchhandler.h"
#include <iostream>
#include "request.h"

// Program to define class for handling QML input values

SearchHandler::SearchHandler(QObject *parent) : QObject(parent) {}

void SearchHandler::parse(const QString &text) {
//    std::cout << text.toStdString() << std::endl;

    // Update API parameters using data retrieval setter function
    std::vector<std::map<std::string, std::string>> eventarr = get_events(
        text.toStdString(), "", "", "", "" , "", "", "", false);

    // Setter branch of get_events function returns blank object --> Getter function branch can be called with updated parameters
    // Need to place code for refreshing map layer here vvv
}
