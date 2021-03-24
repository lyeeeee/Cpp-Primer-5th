//
// Created by liyi on 2020/3/25.
//

#include <iostream>
int main() {

    int sum = 0;
    int i = 50;
    for (;i <= 100; ++i) {
        sum += i;
    }
    std::cout << sum << std::endl;

    std::cout << sum << std::endl;
    for (int i = 10; i >= 0; --i) {
        std::cout << i << " ";
    }

    int v1, v2;
    std::cin >> v1 >> v2;
    for (int i = v1; i <= v2; ++i) {
        std::cout << i << std::endl;
    }
}
