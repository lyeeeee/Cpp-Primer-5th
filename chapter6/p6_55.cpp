//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using  namespace std;
//int func(int,int);
int func1(int i,int j) {
    return i+j;
}
int func2(int i,int j) {
    return i-j;
}
int func3(int i,int j) {
    return i*j;
}
int func4(int i,int j) {
    return i/j;
}
int func(int,int);
typedef decltype(func) f;

int main(){
    vector<f*> fvec = {func1, func2, func3, func4};

    return 0;
}