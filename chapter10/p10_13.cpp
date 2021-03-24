#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;


bool part(string &s) {
    return s.size() >= 5;
}

int main() {
    auto v = std::vector<std::string>{ "a", "as", "aasss", "aaaaassaa", "aaaaaabba", "aaa" };
    auto idx = partition(v.begin(), v.end(), part);
    for (;idx != v.end(); ++idx) {
        cout << *idx << " ";
    }
}