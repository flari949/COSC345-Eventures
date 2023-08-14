#include <iostream>
#include <string>
#include "rapidjson/document.h"
#include "rapidxml/rapidxml.hpp"
#include "data_fetch.h"

/*
    Functions to process API data
*/

int process_json(std::string apiUrl, std::string username, std::string password) {
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
                // Iterate over object instances
                for (rapidjson::SizeType i = 0; i < itemArray.Size(); ++i) {
                    const rapidjson::Value& item = itemArray[i];
                    // Access object fields
                    for (auto& member : item.GetObject()) {
                        if (member.value.IsString()) {
                            const char* value = member.value.GetString();
                            // Data field name can be accessed with member.name.GetString()
                            std::cout << value << std::endl;
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


int process_map(std::string url) {
    std::string mapData = fetchMapAPI(url);

    // std::cout << "Map data: " << mapData << std::endl;

    // Parse the XML data using RapidXML
    rapidxml::xml_document<> doc;

    std::string xmlDataCopy = mapData; // Copy the content
    xmlDataCopy.push_back('\0');

    // Parse the XML data
    doc.parse<0>(&xmlDataCopy[0]); // Parse the XML data

    std::cout << "Parsed xml data" << std::endl;

    std::cout << "Name of my first node is: " << doc.first_node()->name() << std::endl;

    // Accessing specific elements using RapidXML

    return 0;
}
