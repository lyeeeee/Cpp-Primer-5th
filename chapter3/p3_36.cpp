//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool ArrayEqual(const int* beg1,const int* end1,const int* beg2,const int* end2) {
    if ((end1 - beg1) != (end2 - beg2)) {
        return false;
    } else {
        while (beg1 != end1) {
            if (*beg1 != *beg2) {
                return false;
            }
            beg1++;
            beg2++;
        }
        return true;
    }
}
int main() {
    int arr1[3] = { 0, 1, 2 };
	int arr2[3] = { 0, 1, 2 };
    if (ArrayEqual(begin(arr1), end(arr1), begin(arr2), end(arr2))) {
        std::cout << "equal" << endl;
    } else {
        std::cout << "not equal" << endl;
    }
}
