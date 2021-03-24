//
// Created by liyi on 2020/3/25.
//

#include <iostream>
int main() {

    int sum = 0;
    int val = 0;
    while (std::cin >> val) {
        sum += val;
    }
    std::cout << sum << std::endl;
}
