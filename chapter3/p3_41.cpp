//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int arr[] = {1,2,3};
    vector<int> ivec(begin(arr), end(arr));
    for (auto i = ivec.begin(); i != ivec.end(); ++i) {
        cout << *i << endl;
    }
}
