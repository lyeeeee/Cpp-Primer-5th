//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;


int main(int argc, char* argv[]){
    cout << argc << endl;
    string s;
    s += argv[1];
    s += argv[2];
    cout << s << endl;
}
