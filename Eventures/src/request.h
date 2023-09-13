#ifndef REQUEST_H
#define REQUEST_H

#include <vector>
#include <map>
#include <string>

std::vector<std::map<std::string, std::string>> get_events(
    std::string search,
    std::string fields,
    std::string coords,
    std::string radius,
    std::string start_date,
    std::string end_date,
    std::string num_rows,
    std::string row_offset,
    bool get);

std::vector<std::map<std::string, std::string>> get_events();

#endif // REQUEST_H
