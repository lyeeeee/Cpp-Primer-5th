//
// Created by liyi on 2020/3/25.
//

#include <iostream>
int main() {

    int curVal = 0, val = 0;

    if (std::cin >> curVal) {
        int cnt = 1;
        while (std::cin >> val) {
            if (val == curVal) {
                cnt++;
            } else {
                std::cout << "num :" << curVal << " cnt: " << cnt << std::endl;
                curVal = val;
                cnt = 1;
            }
        }

        std::cout << "num :" << curVal << " cnt: " << cnt << std::endl;
    }
}
