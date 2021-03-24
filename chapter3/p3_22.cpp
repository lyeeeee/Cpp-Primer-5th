//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string text = "hello world\n"
                  "dfljk";
    for (string::iterator i = text.begin(); i != text.end() && *i != '\n'; ++i) {
        *i = toupper(*i);
    }
    cout << text << endl;
}
