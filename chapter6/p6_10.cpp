//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;
void swap(int* a, int* b );
int main() {
    int a = 0;
    int b = 1;
    swap(&a,&b);
    cout << a << endl;
    cout << b << endl;
}
void swap(int* a, int* b ) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
