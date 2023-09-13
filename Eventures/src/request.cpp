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
    Program to retrieve EventFinda API responses and store parameter values over application lifespan
*/

std::vector<std::map<std::string, std::string>> get_events(
    std::string search_i,
    std::string fields_i,
    std::string coords_i,
    std::string radius_i,
    std::string start_date_i,
    std::string end_date_i,
    std::string num_rows_i,
    std::string row_offset_i,
    bool get) {

    // Set default search parameters
    static std::string search = ""; // General search parameter
    static std::string fields = "name,url,description~150,datetime_start,datetime_end,point,location_summary"; // Fields to retrieve
    static std::string coords = "-36.84846,174.76334"; // Format: latitude,longitude --> Default : Auckland
    static std::string radius = "50"; // Distance in kilometers -> requires coordinate param be set
    static std::string start_date = ""; // Defaults to now; format : YYYY-MM-DD
    static std::string end_date = ""; // Defaults to 3 years from now; format : YYYY-MM-DD
    static std::string num_rows = "10"; // Number of rows (items) to return
    static std::string row_offset = ""; // Row offset - for paging

    // If function called as setter
    if (!get){
        // If parameter blank, substitute with previous. Use of null character "|" represents empty parameter
        search = (search_i == "|") ? "" : (search_i != "") ? search_i : search;
        fields = (fields_i == "|") ? "" : (fields_i != "") ? fields_i : fields;
        coords = (coords_i != "" || coords_i != "|") ? coords_i : coords;
        radius = (radius_i != "" || radius_i != "|") ? radius_i : radius;
        start_date= (start_date_i != "" || start_date_i != "|") ? start_date_i : start_date;
        end_date = (end_date_i != "" || end_date_i != "|") ? end_date_i : end_date;
        num_rows = (num_rows_i != "" || num_rows_i != "|") ? num_rows_i : num_rows;
        row_offset = (row_offset_i != "" || row_offset_i != "|") ? row_offset_i : row_offset;
        return std::vector<std::map<std::string, std::string>>();
    }

    // If function called as getter

    // Call url generator function
    std::string eventFindaUrl = event_url(search, fields, coords, radius, start_date, end_date, num_rows, row_offset);
    
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    // Request data in map format for simple distributed retrieval
    std::vector<std::map<std::string, std::string>> vectormaps = process_json(eventFindaUrl, username, password);

    return vectormaps;
}

// Default function for ease of use --> retrieval function
std::vector<std::map<std::string, std::string>> get_events() {
    return get_events("","","","","","","","", true);
}
