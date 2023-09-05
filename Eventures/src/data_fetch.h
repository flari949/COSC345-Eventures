/*!
* @file  data_fetch.h
* @brief  fetch data from API
*/

#ifndef DATA_FETCH_H
#define DATA_FETCH_H

#include <string>


/*!
* @brief  fetch data from API
* @param  apiUrl: API url
* @param  username: username
* @param  password: password
* @return  data from API
*/
std::string fetchDataFromAPI(const std::string& apiUrl, const std::string& username, const std::string& password);

#endif
