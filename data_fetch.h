// data_fetch.h

#ifndef DATA_FETCH_H
#define DATA_FETCH_H

#include <string>

std::string fetchDataFromAPI(const std::string& apiUrl, const std::string& username, const std::string& password);
std::string fetchMapAPI(const std::string& url);

#endif
