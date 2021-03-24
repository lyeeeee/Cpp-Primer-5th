//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

//#define NDEBUG
using  namespace std;
void f(){
    cout << "f()" << endl;
}

void f(int){
    cout << "f(int)" << endl;
}

void f(int, int){
    cout << "f(int, int)" << endl;
}

void f(double, double){
    cout << "f(double, double)" << endl;
}

int main(){
    //f(2.56, 42);
    f(42);
    f(42, 0);
    f(2.56, 3.14);

    return 0;
}

