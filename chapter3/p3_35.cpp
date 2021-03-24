//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int arr[5] = {1,1,1,1,1};
    for (int *p = begin(arr); p != end(arr); ++p) {
        *p = 0;
    }
    for (int i = 0;i < 5; ++i) {
        cout << arr[i] << endl;
    }
}
