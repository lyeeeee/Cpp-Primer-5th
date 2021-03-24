#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "p12_19.h"
#include <cstring>

using namespace std;



int main() {
    const char* r1 = "hello ";
    const char* r2 = "world";
    size_t len = strlen(r1) + strlen(r2) + 1;
    char* arr = new char[len]();
    strcat_s(arr, len, r1);
    strcat_s(arr, len, r2);
    cout << arr << endl;

    string s1("hello ");
    string s2("world");
    string s = s1 + s2;
    strcpy_s(arr, len, s.c_str());
    cout << arr << endl;

    delete[] arr;
}