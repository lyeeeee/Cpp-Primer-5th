//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>


using  namespace std;
int func(int,int);
typedef decltype(func) f;
int main(){
    vector<f*> fvec;
    vector<int(*)(int,int)> v;
    return 0;
}

