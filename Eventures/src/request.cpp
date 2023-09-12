/*!
* @mainpage Eventures
* @section intro_sec Introduction
* Eventures is a C++ application that allows users to search for upcoming events in New Zealand cities.
The application uses the Eventfinda API to retrieve event data. The application also uses the LINZ to display the location of events on a map GUI interface.
* @section team_sec Team
* Eventures was developed by a team of four students from the University of Otago as part of the COSC345 Software Engineering paper.
* Luke Piper
* Riley Flanagan
* Eszter Scarlett Herbet
* Kristie Koorts
* @section target_sec Target User
* The target user for Eventures is anyone who is looking for upcoming events in New Zealand cities. Mainly however we want to target students who are looking for events in their city.
*/

#include <string>
#include "event_url.h"
#include "process_raw.h"

#include <vector>
#include <map>

/*
    Program to retrieve EventFinda API responses
*/

std::vector<std::map<std::string, std::string>> get_events(
    std::string search,
    std::string fields,
    std::string coords,
    std::string radius,
    std::string start_date,
    std::string end_date,
    std::string num_rows,
    std::string row_offset) {

    std::string eventFindaUrl = event_url(search, fields, coords, radius, start_date, end_date, num_rows, row_offset);
    
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    // Request data in map format for shared parallel retrieval
    std::vector<std::map<std::string, std::string>> vectormaps = process_json(eventFindaUrl, username, password);

    return vectormaps;
}
