//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec(10, 1);
    for (auto i = ivec.begin(); i != ivec.end(); ++i) {
        *i = 2*(*i);
    }
    for (auto i = ivec.begin(); i != ivec.end(); ++i) {
        cout << *i << endl;
    }
}
