//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> svec;
    string s;
    while (cin >> s) {
        svec.push_back(s);
    }
    for (auto &i : svec) {
        for (char &c : i) {
            c = toupper(c);
        }
    }
    for (auto i : svec) {
        cout << i << " ";
    }
    cout << endl;
}
