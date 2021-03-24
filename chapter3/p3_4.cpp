//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;
//    if (s1 == s2) {
//        cout << "s1 == s2" << endl;
//    } else if (s1 < s2) {
//        cout << s2 << endl;
//    } else {
//        cout << s1 << endl;
//    }
    if (s1.size() == s2.size()) {
        cout << "s1.size() == s2.size()" << endl;
    } else if (s1.size() < s2.size()) {
        cout << s2 << endl;
    } else {
        cout << s1 << endl;
    }
}
