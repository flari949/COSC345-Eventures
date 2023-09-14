/*!
* @file event_url.h
* @brief  Create url for event search based off user parameters inputted.
* Parameters define search for querying EventFina API for actual information of events.
* Most parameters are define by source code, besides from 'search' which is the city the user wants to search for events in.
*/


#ifndef EVENT_URL_H
#define EVENT_URL_H

#include <string>

/*!
* @brief  Create url for event search to query EventFina API for event information
* @param  search: search term
* @param  fields: fields to return
* @param  coords: coordinates
* @param  radius: radius
* @param  start_date: start date
* @param  end_date: end date
* @param  num_rows: number of rows
* @param  row_offset: row offset
* @return  url for event search
*/
std::string event_url(const std::string& search, const std::string& fields, const std::string& coords, const std::string& radius, const std::string& start_date, const std::string& end_date, const std::string& num_rows, const std::string& row_offset);

#endif
