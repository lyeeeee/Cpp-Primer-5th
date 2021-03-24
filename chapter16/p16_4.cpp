#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


template <typename T, typename Q>
T my_find(T beg, T end, Q val) {
    cout << "find" << endl;
    while (beg != end) {
        if (*beg == val) {
            return beg;
        }
        beg++;
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