#include <iostream>
#include <string>
#include <curl/curl.h>

size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append(static_cast<char*>(contents), totalSize);
    return totalSize;
}

std::string fetchDataFromAPI(const std::string& apiUrl, const std::string& username, const std::string& password) {
    CURL* curl = curl_easy_init();
    std::string response;

    if (curl) {
        // Set the URL
        curl_easy_setopt(curl, CURLOPT_URL, apiUrl.c_str());

        // Set the write callback function to handle the response
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        // Set Basic Authentication credentials
        std::string credentials = username + ":" + password;
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
        curl_easy_setopt(curl, CURLOPT_USERPWD, credentials.c_str());

        // Perform the request
        CURLcode res = curl_easy_perform(curl);

        // Check for errors
        if (res != CURLE_OK) {
            std::cerr << "Error during API request: " << curl_easy_strerror(res) << std::endl;
        }

        // Clean up
        curl_easy_cleanup(curl);
    }

    return response;
}

int main() {
    // Replace these with your API endpoint and authentication credentials
    std::string apiUrl = "https://api.eventfinda.co.nz/v2/artists.json?rows=1&q=henry";
    std::string username = "eventure";
    std::string password = "5jryqspxvxkk";

    // Fetch data from the API
    std::string responseData = fetchDataFromAPI(apiUrl, username, password);

    // Print the response data
    std::cout << "API Response:\n" << responseData << std::endl;

    return 0;
}

