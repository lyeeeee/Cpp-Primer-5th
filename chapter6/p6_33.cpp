//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
//合法
using namespace std;
void print(vector<int>::const_iterator beg, vector<int>::const_iterator end) {
    while (beg != end) {
        cout << *beg << endl;
        beg++;
    }
}

int main(void) {
    vector<int> vec{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	print(vec.cbegin(), vec.cend());
}