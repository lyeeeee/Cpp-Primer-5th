//
// Created by liyi on 2020/3/25.
//

#include <iostream>
int main() {

    int sum = 0;
    int i = 50;
    while (i <= 100) {
        sum += i++;
    }
    std::cout << sum << std::endl;
}
