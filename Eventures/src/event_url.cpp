#include <iostream>
#include <sstream>
#include <string>

/* 
    Function to apply API request parameter values to URL
*/

std::string event_url(const std::string search, const std::string fields, const std::string coords, const std::string radius, const std::string start_date, const std::string end_date, const std::string num_rows, const std::string row_offset) {
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
    if (!end_date.empty()) {
        catUrl << "end_date=" << end_date << "&";
    }
    if (!num_rows.empty()) {
        catUrl << "rows=" << num_rows << "&";
    }
    if (!row_offset.empty()) {
        catUrl << "offset=" << row_offset;
    }

    return catUrl.str();
}
