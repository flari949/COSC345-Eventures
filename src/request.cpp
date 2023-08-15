#include <iostream>
#include <string>
#include "event_url.h"
#include "process_raw.h"


/*
    Program to parameterise API url requests
*/

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
    std::cout << "Welcome to Eventures " << std::endl;
    std::cout << "What city are you looking for upcoming events in (Auckland, Wellington, Christchurch, Dunedin): " << std::endl;
    // Scan for user input
    std::string city;
    std::cin >> city;

    // Parameterised search values to be passed to the data retrieval function
    std::string search = "";
    std::string fields = "name,url,description,datetime_start,datetime_end,point,location_summary,category";
    std::string coords = get_coords(city);
    std::string radius = "30";
    std::string start_date = "";
    std::string num_rows = "5";

    std::cout << "Here are the next 5 events in " << city << ": " << std::endl;
    std::string eventFindaUrl = event_url(search, fields, coords, radius, start_date, num_rows);
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    process_json(eventFindaUrl, username, password);

    // LINZ API
    std::string mapAPIKey = "c01h7e45g7q2sgxt0me0jsn3542";
    std::string mapAPIUrl = "https://basemaps.linz.govt.nz/v1/tiles/aerial/NZTM2000Quad/WMTSCapabilities.xml?api=" + mapAPIKey;
    printf("\nMap API url: %s\n", mapAPIUrl.c_str());
    process_map(mapAPIUrl);
  
    return 0;
}
