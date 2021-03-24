//
// Created by liyi on 2020/4/2.
//

#include "Chapter6.h"
#include <iostream>
using namespace std;
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
int print_abs(int val) {
    cout << abs(val) << endl;
    return 0;
}
int static_v() {
    static int i = 0;
    return i++;
}
