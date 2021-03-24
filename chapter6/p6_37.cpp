//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;
//string (&func(string (&arr)[10]))[10];

using arrType = int[10];
arrType & func1(arrType& arr);

auto func2(arrType& arr) -> string(&)[10];

string arr[10];
decltype(arr)& func3(decltype(arr)& v);

int main(void){

}



