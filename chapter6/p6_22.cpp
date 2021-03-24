//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
void swapPointer(int*& i, int*& j);
int main() {
    int i = 3,j = 4;
    int* x = &i;
    int* y = &j;
    swapPointer(x,y);
    *x = 1;
    *y = 2;
    cout << i << " " << j << endl;
}

void swapPointer(int*& i, int*& j) {
    int* tmp = i;
    i = j;
    j = tmp;
}
