//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int ia[3][4] = {
            {0,1,2,3},
            {4,5,6,7},
            {8,9,10,11}
    };
    for (const int (&arr)[4] : ia) {
        for (const int &i : arr) {
            std::cout << i << " ";
        }   
        std::cout << endl;
    }

    for (size_t i = 0;i < 3; ++i) {
        for (size_t j = 0;j < 4; ++j) {
            std::cout << ia[i][j] << " ";
        }
        std::cout << endl;
    }

    for (int (*i)[4] = begin(ia); i != end(ia); ++i ) {
        for (int *j = *i; j < (*i) + 4; ++j) {
            std::cout << *j << " ";
        }
        std::cout << endl;
    }
}
