#include <iostream>
#include <curl/curl.h>
#include <string>
#include <json/json.h>  // JSON parsing library

// Deribit API details
const std::string BASE_URL = "https://test.deribit.com";
std::string client_id = "your_client_id";
std::string client_secret = "your_client_secret";
std::string access_token;

// Utility to handle HTTP requests
std::string httpRequest(const std::string& url, const std::string& params) {
    CURL* curl;
    CURLcode res;
    std::string response;
    curl = curl_easy_init();

    if(curl) {
        curl_easy_setopt(curl, CURLOPT_URL, (BASE_URL + url).c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params.c_str());

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* data, size_t size, size_t nmemb, std::string* buffer) {
            buffer->append((char*)data, size * nmemb);
            return size * nmemb;
        });

        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    return response;
}

// Authenticate and get access token
void authenticate() {
    std::string url = "/api/v2/public/auth";
    std::string params = "client_id=" + client_id + "&client_secret=" + client_secret + "&grant_type=client_credentials";
    std::string response = httpRequest(url, params);
    
    Json::Reader reader;
    Json::Value jsonResponse;
    reader.parse(response, jsonResponse);
    
    access_token = jsonResponse["result"]["access_token"].asString();
    std::cout << "Access Token: " << access_token << std::endl;
}
