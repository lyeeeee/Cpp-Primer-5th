//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> v1(10,42);
    vector<int> v2{42,42,42,42,42,42,42,42,42,42};
    vector<int> v3;
    for (int i = 0;i < 10; ++i) {
        v3.push_back(42);
    }
}
