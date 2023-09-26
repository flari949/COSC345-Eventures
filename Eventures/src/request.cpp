/*!
* @mainpage Eventures
* @section intro_sec Introduction
* Eventures is a C++ application that allows users to search for upcoming events in New Zealand cities.
The application uses the Eventfinda API to retrieve events and event data.
The application also uses the ArcGIS to display the location of events on a map GUI interface.
The combinations of these two datasets aims to help New Zealanders find events and help great events been found and attended.

* @section Features
* VERSION Beta Release
* *Some features might not be currently present in application version, if not then feature is goal for future releases*
* - Fetch up to date event data from EventFinda API
* - ArcGIS map display given a comprehensive map of New Zealand
* - Zoom In/Out through map
* - Search city filter enabling the filtering of events in specific cities
* - Detailed description of event with relevant data
* - Filtering by event type
* - Saved interested events
*
* @section Development
* This application development is set as a semester long project for Otago Universitys COSC345.
* The development of this application has been taking place between 10 July up to present date,
* with the final release date set for the 6th October. The source is built on the C++ langauge using QT as the IDE for graphics.
* The application follows version contrtol and continous integration practices, in parrelllel with statis analysis (Codeacy) and code coverage tools (CodeCov).
* Developers wanting to develop the Eventures application further are welcomed, however all pull requests will be looked over before merge to master.
* Steps for installing QT then compiling, building and running program can be found inside GitHub repositiories README.
*
* @section Team
* Eventures was developed by a team of four students from the University of Otago as part of the COSC345 Software Engineering paper.
* Luke Piper
* Riley Flanagan
* Eszter Scarlett Herbet
* Kristie Koorts
*
* @section target_sec Target User
* The target user for Eventures is anyone who is looking for upcoming events in New Zealand cities.
* Mainly however we want to target students who are looking for events in their city.
* Students new to their univeristy city using our app can make the most of their university experience
*  and join clubs/meet new friends to help the adjustment away for their previous city.
*
* @section Source Code
* For detailed documentation on the source codes found with the project,
* please refer the Files->Files List in documetnation to get detailed documentation on specfic files
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
    static std::string fields = "name,url,description,datetime_start,datetime_end,point,location_summary"; // Fields to retrieve
    static std::string coords = "-41.35249807015349,173.07275377115386"; // Format: latitude,longitude --> Default : Wellington
    static std::string radius = "2000"; // Distance in kilometers -> requires coordinate param be set
    static std::string start_date = ""; // Defaults to now; format : YYYY-MM-DD
    static std::string end_date = ""; // Defaults to 3 years from now; format : YYYY-MM-DD
    static std::string num_rows = "20"; // Number of rows (items) to return --> Max : 20
    static std::string row_offset = "0"; // Row offset - for paging

    // If function called as setter
    if (!get){
        // If parameter blank, substitute with previous. Use of null character "|" represents empty parameter
        search = (search_i == "|") ? "" : (search_i != "") ? search_i : search;
        fields = (fields_i == "|") ? "" : (fields_i != "") ? fields_i : fields;
        coords = (coords_i != "") ? coords_i : coords;
        radius = (radius_i != "") ? radius_i : radius;
        start_date = (start_date_i != "") ? start_date_i : start_date;
        end_date = (end_date_i != "") ? end_date_i : end_date;
        num_rows = (num_rows_i != "") ? num_rows_i : num_rows;
        row_offset = (row_offset_i != "") ? row_offset_i : row_offset;

        // Remove space characters from string
        size_t space = search.find(" ");
        while (space != std::string::npos) {
            search.erase(space, 1); // Erase the space character
            space = search.find(" ", space + 1); // Find the next space
        }

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
