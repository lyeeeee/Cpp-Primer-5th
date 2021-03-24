//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    string s;
    string pre;
    while (cin >> s) {
        if (s == pre && isupper(s[0])) {
            cout << s << endl;
            break;
        } else {
            pre = s;
        }
    }
    if (s != pre) {
        cout << "no repeat word" << endl;
    }
}
