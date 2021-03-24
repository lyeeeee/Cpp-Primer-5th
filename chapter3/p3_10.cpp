//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string s;
    cin >> s;
    string ret;
    for (string::size_type i = 0;i < s.size(); ++i) {
        if (!ispunct(s[i])) {
            ret += s[i];
        }
    }
    cout << ret << endl;
}
