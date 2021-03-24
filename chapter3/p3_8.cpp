//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    // while
    string s("hello world!");
    decltype(s.size()) i = 0;
    while (i < s.size()) {
        s[i++] = 'X';
    }
    cout << s << endl;
    // for
    s = "hello world!";
    for (auto i = 0;i < s.size(); ++i) {
        s[i] = 'X';
    }
    cout << s << endl;
}
