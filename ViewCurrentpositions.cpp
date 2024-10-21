View Current Positions:
void viewPositions() {
    std::string url = "/api/v2/private/get_positions";
    std::string params = "access_token=" + access_token;
    std::string response = httpRequest(url, params);
    std::cout << "Positions Response: " << response << std::endl;
}
