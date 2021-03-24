//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec(11, 0);
    unsigned grade;
    auto beg = ivec.begin();
    while (cin >> grade) {
        if (grade <= 100) {
            (*(beg+(grade/10)))++;
        }
    }
    for (auto i = ivec.begin(); i != ivec.end(); ++i) {
        cout << *i << endl;
    }

}
