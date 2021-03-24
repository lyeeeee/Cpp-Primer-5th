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
    for (auto &i : ia) {
        for (auto j : i) {
            cout << j << endl;
        }
    }

    for (size_t i = 0;i < 3; ++i) {
        for (size_t j = 0;j < 4; ++j) {
            cout << ia[i][j] << endl;
        }
    }

    for (auto i= ia; i < ia+3; ++i) {
        for (int* j = *i; j < *i+4; ++j) {
            cout << *j << endl;
        }
    }
}
