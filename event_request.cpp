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
    
return 0;
}
