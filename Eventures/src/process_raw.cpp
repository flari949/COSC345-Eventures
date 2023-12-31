#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stdexcept>
#include "rapidjson/document.h"
#include "data_fetch.h"

/*
    Functions to process API data
*/

std::vector<std::map<std::string, std::string>> process_json(const std::string& apiUrl, const std::string& username, const std::string& password) {
    // Fetch data from the API
    std::string responseData = fetchDataFromAPI(apiUrl, username, password);

    // Parse the JSON string
    rapidjson::Document doc;
    doc.Parse(responseData.c_str());

    // Check if parsing was successful
    if (!doc.HasParseError() && doc.IsObject()) {
        // Check response contains appropriate data
        if (doc.MemberCount() >= 2) {
            auto lastMember = doc.MemberEnd() - 1;
            const rapidjson::Value &itemArray = lastMember->value;
            // Check item array format
            if (itemArray.IsArray()) {
                // Create dynamic array for data containerisation
                std::vector<std::map<std::string, std::string>> results;
                // Iterate over object instances
                for (rapidjson::SizeType i = 0; i < itemArray.Size(); ++i) {
                    const rapidjson::Value& item = itemArray[i];
                    // Access object fields
                    std::map<std::string, std::string> event_values;
                    for (auto& member : item.GetObject()) {
                        if (member.value.IsString()) {
                            event_values[member.name.GetString()] = member.value.GetString();
                        }
                        // Check if field contains multiple values
                        else if (member.value.IsObject()) {
                            // Check for coordinate values
                            if (member.value.HasMember("lat") && member.value.HasMember("lng")) {
                                for (auto& val : member.value.GetObject()) {
                                    event_values[val.name.GetString()] = std::to_string(val.value.GetFloat());
                                }
                            }
                        }
                    }
                    results.push_back(event_values);
                }
                return results;
            } else {
                std::cerr << "Object itemArray is not an array" << std::endl;
                abort();
            }
        } else {
            // Return blank object on empty or not found result
            std::cout << "Value not found or empty" << std::endl;
            return std::vector<std::map<std::string, std::string>>();
        }
    } else {
        std::cerr << "Failed to parse JSON data" << std::endl;
        abort();
    }
    std::cerr << "Failed to process JSON data" << std::endl;
    abort();
}
