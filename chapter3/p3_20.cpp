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
    for (auto i = 0;i < ivec.size()-1;++i) {
        cout << ivec[i] + ivec[i+1] << endl;
    }
}
