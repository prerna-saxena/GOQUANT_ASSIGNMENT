Get Order Book:
void getOrderBook(const std::string& symbol) {
    std::string url = "/api/v2/public/get_order_book?instrument_name=" + symbol;
    std::string response = httpRequest(url, "");
    std::cout << "Orderbook Response: " << response << std::endl;
}
