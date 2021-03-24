//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
//    string s1 = "hello";
//    string s2 = "world";
//    if (s1 > s2) {
//        cout << "s1 > s2" << endl;
//    } else if (s1 == s2) {
//        cout << "s1 == s2" << endl;
//    } else {
//        cout << "s1 < s2" << endl;
//    }
    char* s1 = "hello";
    char* s2 = "world";
    if (strcmp(s1,s2) > 0) {
        cout << "s1 > s2" << endl;
    } else if (strcmp(s1,s2) == 0) {
        cout << "s1 == s2" << endl;
    } else {
        cout << "s1 < s2" << endl;
    }
}
