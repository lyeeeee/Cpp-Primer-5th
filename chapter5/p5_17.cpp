//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    vector<int> v1 = {0,1,1,2};
    vector<int> v2 = {0,1,1,2,3,5,8};
    for (auto i = 0;i < min(v1.size(), v2.size()); ++i) {
        if (v1[i] != v2[i]) {
            cout << "false" << endl;
            break;
        }
    }
    cout << "true" << endl;
}
