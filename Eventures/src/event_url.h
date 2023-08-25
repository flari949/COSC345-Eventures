/*!
* @file event_url.h
* @brief  create url for event search based off user parameters inputted
*/

#ifndef EVENT_URL_H
#define EVENT_URL_H

#include <string>

/*!
* @brief  create url for event search
* @param  search: search term
* @param  fields: fields to return
* @param  coords: coordinates
* @param  radius: radius
* @param  start_date: start date
* @param  num_rows: number of rows
* @param  row_offset: row offset
* @return  url for event search
*/
std::string event_url(std::string search, std::string fields, std::string coords, std::string radius, std::string start_date, std::string num_rows, std::string row_offset);

#endif
