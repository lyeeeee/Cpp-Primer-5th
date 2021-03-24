//
// Created by liyi on 2020/3/26.
//

#include <iostream>

struct Sales_data {
    std::string book_no;
    unsigned units_sold;
    double revenue;
};

int main() {
    Sales_data data;
    double price;
    while (std::cin >> data.book_no) {
        std::cin >> data.units_sold;
        std::cin >> price;
        data.revenue = data.units_sold * price;
        std::cout << data.book_no << " " << data.units_sold << " " << data.revenue << std::endl;
    }
    return 0;
}
