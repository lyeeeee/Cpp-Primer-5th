//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
void reset(int&);
int main() {
    int x = 3;
    reset(x);
    cout << x << endl;
}
void reset(int& a) {
    a = 0;
}
