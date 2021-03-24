//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * b错，类型不一样
 * 
*/
int main() {
    vector<vector<int>> ivec;
    // erro
    // vector<string> svec = ivec;
    vector<string> svec(10, "null");
}
