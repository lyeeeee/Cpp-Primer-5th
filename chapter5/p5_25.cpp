//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int i1, i2;
    enter:
    cin >> i1 >> i2;
    try {
        if (i2 == 0) {
            throw runtime_error("divide zero");
        }
        cout << i1/i2 << endl;
    } catch (runtime_error error) {
        cout << error.what() << endl;
        cout << "try enter again ?(yes/no)";
        string s;
        cin >> s;
        if (s.empty() || s == "no") {
            return 0;
        } else {
            goto enter;
        }
    }
}
