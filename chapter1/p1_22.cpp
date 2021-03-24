//
// Created by liyi on 2020/3/25.
//

#include <iostream>
#include "../include/Sales_item.h"
int main() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item tmp;
        while (std::cin >> tmp) {
            if (total.isbn() == tmp.isbn()) {
                total += tmp;
            } else {
                std::cout << total << std::endl;
                total = tmp;
            }
        }
        std::cout << total << std::endl;
    } else {
        std::cout << "error, no data" << std::endl;
    }
}
