//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    vector<int> ivec = {1,2,3};
    int arr[3];
    for (int i = 0;i < ivec.size(); ++i) {
        arr[i] = ivec[i];
    }
}
