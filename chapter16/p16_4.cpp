#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;

template <typename T, typename D>
T my_find(const T& beg, const T&end, const D&target) {
    T p = beg;
    while (beg != end) {
        if (*p == target) {
            return p;
        }
        p++;
    }
    return end;
}



int main() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << *(my_find(v.begin(), v.end(), 3)) << endl;
}