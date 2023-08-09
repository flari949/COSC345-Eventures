#include <iostream>
#include <string>
#include <rapidjson/document.h>
#include "data_fetch.h"

/*
    Program to process API JSON data
*/

int process_json(std::string apiUrl, std::string username, std::string password) {
    // Fetch data from the API
    std::string responseData = fetchDataFromAPI(apiUrl, username, password);

    // Print the response data
    // std::cout << "API Response:\n" << responseData << std::endl;

    // Parse the JSON string
    rapidjson::Document doc;
    doc.Parse(responseData.c_str());

    // Check if parsing was successful
    if (!doc.HasParseError() && doc.IsObject()) {

        // Check response contains appropriate data
        if (doc.MemberCount() >= 2) {
            auto lastMember = doc.MemberEnd() - 1;
            const rapidjson::Value& itemArray = lastMember->value;
            // Check item array format
            if (itemArray.IsArray()) {
                // Iterate over object instances
                for (rapidjson::SizeType i = 0; i < itemArray.Size(); ++i) {
                    const rapidjson::Value& item = itemArray[i];
                    // Check item format
                    if (item.IsObject()) {
                        // URL data
                        if (item.HasMember("url") && item["url"].IsString()) {
                            const char* url = item["url"].GetString();
                            std::cout << "Response url: " << url << std::endl;
                        }
                        // Address data
                        if (item.HasMember("address") && item["address"].IsString()) {
                            const char* url = item["address"].GetString();
                            std::cout << "Response address: " << url << std::endl;
                        }
                        // Unique id data - Doesn't pay respect to endpoint
                        if (item.HasMember("id") && item["id"].IsString()) {
                            const char* url = item["id"].GetString();
                            std::cout << "Response id: " << url << std::endl;
                        }
                        // Name data - Doesn't pay respect to endpoint
                        if (item.HasMember("name") && item["name"].IsString()) {
                            const char* url = item["name"].GetString();
                            std::cout << "Response name: " << url << std::endl;
                        }
                    }
                }
            } else {
                std::cerr << "Object itemArray is not an array" << std::endl;
            }
        } else {
            std::cerr << "Value not found or empty" << std::endl;
        }
    } else {
        std::cerr << "Failed to parse JSON data" << std::endl;
    }

    return 0;
}

