#include <iostream>
#include <string>
#include "event_url.h"
#include "process_raw.h"


/*
    Program to parameterise API url requests
*/

int main() {

    // Parameterised search values to be passed to the data retrieval function
    std::string search = "concert";
    std::string fields = "name,url";
    std::string coords = "";
    std::string radius = "5";
    std::string start_date = "";
    std::string num_rows = "2";

    std::string eventFindaUrl = event_url(search, fields, coords, radius, start_date, num_rows);
    
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    process_json(eventFindaUrl, username, password);

    // LINZ API
    std::string mapAPIKey = "c01h7e45g7q2sgxt0me0jsn3542";
    std::string mapAPIUrl = "https://basemaps.linz.govt.nz/v1/tiles/aerial/NZTM2000Quad/WMTSCapabilities.xml?api=" + mapAPIKey;
    printf("Map API url: %s\n", mapAPIUrl.c_str());
    process_map(mapAPIUrl);
  
    return 0;
}
