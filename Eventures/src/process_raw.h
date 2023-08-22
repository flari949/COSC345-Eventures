/*!
* @file process_raw.h
* @brief process data generated from APIs
*/

#ifndef PROCESS_RAW_H
#define PROCESS_RAW_H

#include <string>

/*!
* @brief Processes the raw JSON data from the EventFinda API
*
* @param apiUrl The url to fetch data from
* @param username The username to use for authentication
* @param password The password to use for authentication
* @return int The status code
*/
int process_json(std::string apiUrl, std::string username, std::string password);

/*!
* @brief Processes the raw JSON data from the LINZ API
*
* @param mapAPIUrl The url to fetch data from
* @return int The status code
*/
int process_map(std::string mapAPIUrl);

#endif
