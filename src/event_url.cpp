#include <iostream>
#include <sstream>
#include <string>

/* 
    Function to apply API request parameter values to URL
*/

std::string event_url(std::string search, std::string fields, std::string coords, std::string radius, std::string start_date, std::string num_rows, std::string row_offset) {
    // EventFinda API
    std::string baseUrl = "https://api.eventfinda.co.nz/v2/events.json?";
    // Apply search parameters to API request URL
    std::ostringstream catUrl;
    catUrl << baseUrl;
    if (!search.empty()) {
        catUrl << "autocomplete=" << search << "&";
    }
    if (!fields.empty()) {
        catUrl << "fields=event:(" << fields << ")&";
    }
    if (!coords.empty()) {
        catUrl << "point=" << coords << "&radius=" << radius << "&";
    }
    if (!start_date.empty()) {
        catUrl << "start_date=" << start_date << "&";
    }
    if (!num_rows.empty()) {
        catUrl << "rows=" << num_rows << "&";
    }
    if (!row_offset.empty()) {
        catUrl << "offset=" << row_offset;
    }

    return catUrl.str();
}
