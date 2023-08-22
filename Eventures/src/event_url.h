/*!
* @file event_url.h
* @brief Returns the url for the EventFinda API based off query parameters
*/

#ifndef EVENT_URL_H
#define EVENT_URL_H

#include <string>

/*!
* @brief Returns the url for the EventFinda API
* 
* @param search The search parameter
* @param fields The fields to retrieve
* @param coords The coordinates to search around
* @param radius The radius to search within
* @param start_date The start date to search from
* @param num_rows The number of rows to return
* @param row_offset The row offset to use
* @return std::string The url for the EventFinda API
*/
std::string event_url(std::string search, std::string fields, std::string coords, std::string radius, std::string start_date, std::string num_rows, std::string row_offset);

#endif
