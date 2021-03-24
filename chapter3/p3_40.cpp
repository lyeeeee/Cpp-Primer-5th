//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    char arr1[] = "hello";
    char arr2[] = "world";
    char ret[strlen(arr1) + strlen(arr2)];
    strcpy(ret, arr1);
    strcat(ret,arr2);
    cout << ret << endl;
}
