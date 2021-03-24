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
    Sales_data total;
    double totalPrice;
    
    if (std::cin >> total.book_no >> total.units_sold >> totalPrice) {
        total.revenue = total.units_sold*totalPrice;
        Sales_data tmp;
        double price;
        while (std::cin >> tmp.book_no >> tmp.units_sold >> price) {
            if (tmp.book_no == total.book_no) {
                total.units_sold += tmp.units_sold;
                total.revenue = total.units_sold * totalPrice;
            } else {
                std::cout << total.book_no << " " << total.units_sold << " " << total.revenue << std::endl;
                total.book_no = tmp.book_no;
                total.units_sold = tmp.units_sold;
                total.revenue = tmp.revenue;
            }
        }
    } else {
        std::cout << "no data!" << std::endl;
    }
}
