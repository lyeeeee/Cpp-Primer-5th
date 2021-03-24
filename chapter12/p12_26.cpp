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
    int n = 10;
    allocator<string> allo;
    string* arr = allo.allocate(n);
    string tmp;
    string* p = arr;
    while (cin >> tmp && p != arr + n) {
        allo.construct(p, tmp);
        p++;
    }
    const size_t num = p - arr;
    p = arr;
    for (int i = 0;i < num; ++i) {
        cout << *p << " ";
        p++;
    }
    cout << endl;

    allo.deallocate(arr, n);
}