//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
int static_v();
int main() {
    for (int i = 0;i < 100; ++i) {
        cout << static_v() << endl;
    }
}
int static_v() {
    static int i = 0;
    return i++;
}
