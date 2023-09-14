/*!
* @file process_raw.h
* @brief  Process raw data returned from API.
* Reads JSON returned data from EventFinaAPI, to help display the event information to program for user.
*/

#ifndef PROCESS_RAW_H
#define PROCESS_RAW_H

#include <string>
#include <vector>
#include <map>

/*!
* @brief  Process raw data returned from API and process it in to readable form to extract relevant event data
* @param  apiUrl: API url
* @param  username: username
* @param  password: password
* @return  0 if success, 1 if failure
*/
std::vector<std::map<std::string, std::string>> process_json(const std::string& apiUrl, const std::string& username, const std::string& password);

#endif
