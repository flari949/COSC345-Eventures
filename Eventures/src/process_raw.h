/*!
* @file process_raw.h
* @brief  process raw data returned from API
*/

#ifndef PROCESS_RAW_H
#define PROCESS_RAW_H

#include <string>
#include <vector>
#include <map>

/*!
* @brief  process raw data returned from API
* @param  apiUrl: API url
* @param  username: username
* @param  password: password
* @return  0 if success, 1 if failure
*/
std::vector<std::map<std::string, std::string>> process_json(std::string apiUrl, std::string username, std::string password);
//int process_map(std::string mapAPIUrl);

#endif
