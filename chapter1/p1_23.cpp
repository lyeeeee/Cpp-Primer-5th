//
// Created by liyi on 2020/3/25.
//

#include <iostream>
#include "../include/Sales_item.h"
int main() {
    Sales_item total;
    if (std::cin >> total) {
        Sales_item tmp;
        int cnt = 1;
        while (std::cin >> tmp) {
            if (total.isbn() == tmp.isbn()) {
                total += tmp;
                cnt++;
            } else {
                std::cout << total << " " << cnt << std::endl;
                total = tmp;
                cnt = 1;
            }
        }
        std::cout << total << " " << cnt << std::endl;
    } else {
        std::cout << "error, no data" << std::endl;
    }
}
