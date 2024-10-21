Cancel an Order:

void cancelOrder(const std::string& order_id) {
    std::string url = "/api/v2/private/cancel";
    std::string params = "access_token=" + access_token + "&order_id=" + order_id;
    std::string response = httpRequest(url, params);
    std::cout << "Cancel Response: " << response << std::endl;
}
