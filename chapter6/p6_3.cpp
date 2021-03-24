//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
int fact(int val);
int main() {
    cout << fact(2) << endl;
    cout << fact(4) << endl;
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
