Placing an Order:


void placeOrder(const std::string& symbol, const std::string& side, double quantity, double price) {
    std::string url = "/api/v2/private/buy";  // or "/sell"
    std::string params = "access_token=" + access_token + "&instrument_name=" + symbol +
                         "&amount=" + std::to_string(quantity) + "&price=" + std::to_string(price);
    std::string response = httpRequest(url, params);
    std::cout << "Order Response: " << response << std::endl;
}
