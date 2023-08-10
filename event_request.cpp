#include <iostream>
#include <string>
#include "process_json.h"

/*
    Program to parameterise API url requests
*/

int main() {
    std::string apiUrl = "https://api.eventfinda.co.nz/v2/artists.json?rows=1&q=michael";
    // Need to add as env variables for security
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    process_json(apiUrl, username, password);

    // LINZ API
    std::string mapAPIKey = "c01h7e45g7q2sgxt0me0jsn3542";
    std::string mapAPIUrl = "https://basemaps.linz.govt.nz/v1/tiles/aerial/NZTM2000Quad/WMTSCapabilities.xml?api=" + mapAPIKey;
    printf("Map API url: %s\n", mapAPIUrl.c_str());
    process_map(mapAPIKey, mapAPIUrl);
  
    return 0;
}
