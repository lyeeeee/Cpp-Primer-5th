//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using  namespace std;
inline bool is_shorter(const string &l, const string &r){
    return l.size() < r.size();
}

int main(){
    cout << is_shorter("pezy", "mooophy") << endl;
    return 0;
}


