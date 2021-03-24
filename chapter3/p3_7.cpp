//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s("hello world!");
    for (char & c : s) {
        c = 'X';
    }
    cout << s << endl;
}
