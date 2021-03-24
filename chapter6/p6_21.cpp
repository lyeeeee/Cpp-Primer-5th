//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
int compare(int i, const int* j);
int main() {
    int i = 3,j = 4;
    cout << compare(i,&j) <<endl;
}
int compare(int i, const int* j) {
    return i - *j;
}
