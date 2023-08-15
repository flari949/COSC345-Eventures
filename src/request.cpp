#include <iostream>
#include <string>
#include "event_url.h"
#include "process_raw.h"


/*
    Program to parameterise API url requests
*/

// Return coords (lat, long) for a given city
std::string get_coords(std::string city) {
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

int main() {
    // User interface
    std::cout << "Welcome to Eventures " << std::endl;
    std::cout << "What city are you looking for upcoming events in (Auckland, Wellington, Christchurch, Dunedin): " << std::endl;
    // Scan for user input
    std::string city;
    std::cin >> city;

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

    std::cout << "Here are the next " << num_rows << " events in " << city << ": " << std::endl;
    process_json(eventFindaUrl, username, password);

    // LINZ API
    std::string mapAPIKey = "c01h7e45g7q2sgxt0me0jsn3542";
    std::string mapAPIUrl = "https://basemaps.linz.govt.nz/v1/tiles/aerial/NZTM2000Quad/WMTSCapabilities.xml?api=" + mapAPIKey;
    printf("\n\nMap API url: %s\n", mapAPIUrl.c_str());
    process_map(mapAPIUrl);
  
    return 0;
}
