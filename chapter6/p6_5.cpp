//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
int print_abs(int val);
int main() {
    int i;
    cin >> i;
    print_abs(i);
}
int print_abs(int val) {
    cout << abs(val) << endl;
}
