//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
bool containsUpper(const string& s);
void toLower(string& s);
int main() {
    string s = "Hello";
    cout << containsUpper(s) << endl;
    toLower(s);
    cout << s << endl;
}
bool containsUpper(const string& s) {
    for (auto c : s) {
        if (isupper(c))
            return true;
    }
    return false;
}

void toLower(string& s) {
    for (char& c : s) {
        c = tolower(c);
    }
}
