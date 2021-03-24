//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include "Chapter6.h"

using namespace std;
int main() {
    int i = 0;
    cout << "please enter a positive integer:" << endl;
    cin >> i;
    cout << fact(i) << endl;
}
int fact(int val) {
    if (val < 0) return -1;
    if (val == 0) {
        return 1;
    }
    int ret = 1;
    while (val > 1) {
        ret *= val--;
    }
    return ret;
}
