//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int i1, i2;
    cin >> i1 >> i2;
    if (i2 == 0) {
        throw runtime_error("divide zero");
    }
    cout << i1/i2;
}
