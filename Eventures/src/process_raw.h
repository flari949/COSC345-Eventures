/*!
* @file process_raw.h
* @brief  process raw data returned from API
*/

#ifndef PROCESS_RAW_H
#define PROCESS_RAW_H

#include <string>

/*!
* @brief  process raw data returned from API
* @param  apiUrl: API url
* @param  username: username
* @param  password: password
* @return  0 if success, 1 if failure
*/
int process_json(std::string apiUrl, std::string username, std::string password);
//int process_map(std::string mapAPIUrl);

#endif
