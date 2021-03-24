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
    Sales_data book1, book2;
    double price;
    std::cin >> book1.book_no >> book1.units_sold >> price;
    std::cin >> book2.book_no >> book2.units_sold >> price;
    book1.revenue = book1.units_sold*price;
    book2.revenue = book2.units_sold*price;
    book2.units_sold += book1.units_sold;
    book2.revenue += book1.revenue;

    std::cout << book2.book_no << " " << book2.revenue << " " << book2.units_sold << std::endl;
}
