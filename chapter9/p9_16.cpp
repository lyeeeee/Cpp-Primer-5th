#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

bool compare(list<int>& l, vector<int>& v) {
    if (l.size() != v.size()) return false;
    auto i = l.begin();
    for ( auto j = v.begin(); i != l.end(); ++i, ++j) {
        if (*i != *j) return false;
    }
    return true;
}
int main() {
    
}