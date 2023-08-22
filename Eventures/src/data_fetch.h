/*!
* @file data_fetch.h
* @brief Fetches data from the EventFinda API and LINZ API
*/
#ifndef DATA_FETCH_H
#define DATA_FETCH_H

#include <string>

/*!
 * @brief Fetches data from the EventFinda API
 * 
 * @param apiUrl The url to fetch data from
 * @param username The username to use for authentication
 * @param password The password to use for authentication
 * @return std::string The data returned from the API
 */
std::string fetchDataFromAPI(const std::string& apiUrl, const std::string& username, const std::string& password);

/*!
* @brief Fetches data from the LINZ API
* @param url The url to fetch data from
* @return std::string The data returned from the API
*/
std::string fetchMapAPI(const std::string& url);

#endif
