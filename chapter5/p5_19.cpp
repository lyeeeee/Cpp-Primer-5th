//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    string s1;
    string s2;
    do {
        cout << "please enter two string:" << endl;
        cin >> s1 >> s2;
        cout << (s1.size() < s2.size() ? s1 : s2) << " is shorter." << endl;
        cout << "continue ? (yes/no)";
        cin >> s1;
    } while (s1 == "yes");
}
