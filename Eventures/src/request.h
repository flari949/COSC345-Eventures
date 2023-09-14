/*!
* @file request.h
* @brief This file contains declarations for functions related to retrieving events.
*/
#ifndef REQUEST_H
#define REQUEST_H

#include <vector>
#include <map>
#include <string>

/*!
 * \brief Function sends a request to retrieve events based on the provided parameters.
 * \param search city
 * \param fields
 * \param coords
 * \param radius (km)
 * \param start_date
 * \param end_date
 * \param num_rows - amount of events returned
 * \param row_offset - offset the starting event in list
 * \return
 */
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
