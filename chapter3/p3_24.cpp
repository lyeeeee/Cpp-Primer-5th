//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> ivec;
    int val;
    while (cin >> val) {
        ivec.push_back(val);
    }
    for (auto i = ivec.begin();i != ivec.end()-1;++i) {
        cout << *i + *(i+1) << endl;
    }
}
