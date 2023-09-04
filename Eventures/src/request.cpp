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

#include <iostream>
#include <string>
#include "event_url.h"
#include "process_raw.h"

#include <vector>
#include <map>


/*
    Program to parameterise API url requests   ---------      OVERRIDE PROGRAM WITH MAP INTERFACE SEARCH QUERY VALUES ETC
*/

// Return coords (lat, long) for a given city
std::string get_coords(std::string const city) {
    std::string coords = "";
    if(city == "Auckland") {
        coords = "-36.84846,174.76334";
    } else if(city == "Wellington") {
        coords = "-41.28664,174.77557";
    } else if(city == "Christchurch") {
        coords = "-43.5309,172.6365";
    } else if(city == "Dunedin") {
        coords = "-45.87416,170.50361";
    } else {
        std::cout << "Sorry, we don't have any events listed for that city. Please try again." << std::endl;
    }
    return coords;
}

int get_events() {
    std::string city = "Auckland";

    // Parameterised search values to be passed to the data retrieval function
    std::string search = ""; // General search parameter
    std::string fields = "name,url,description~150,datetime_start,datetime_end,point,location_summary"; // Fields to retrieve
    std::string coords = get_coords(city); // Format: latitude,longitude
    std::string radius = "5"; // Distance in kilometers
    std::string start_date = ""; // Defaults to now; format: YYYY-MM-DD
    std::string num_rows = "5"; // Number of rows (items) to return
    std::string row_offset = ""; // Row offset - for paging

    std::string eventFindaUrl = event_url(search, fields, coords, radius, start_date, num_rows, row_offset);
    
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    // Request data in map format for shared parallel retrieval
    std::vector<std::map<std::string, std::string>> vectormaps = process_json(eventFindaUrl, username, password);
    for (int x=0; x < vectormaps.size(); x++) {
        std::map<std::string, std::string> event = vectormaps[x];
        std::cout << vectormaps[x]["name"] << std::endl;
    }

    return 0;
}
