Modify an Order:


void modifyOrder(const std::string& order_id, double new_price) {
    std::string url = "/api/v2/private/edit";
    std::string params = "access_token=" + access_token + "&order_id=" + order_id +
                         "&new_price=" + std::to_string(new_price);
    std::string response = httpRequest(url, params);
    std::cout << "Modify Response: " << response << std::endl;
}
