#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> fl = {1,2,3,4,5,6,7,8,9};
    auto prev = fl.before_begin();
    auto cur = fl.begin();
    while (cur != fl.end()) {
        if (*cur % 2 != 0) {
            cur = fl.erase_after(prev);
        } else {
            prev = cur;
            ++cur;
        }
    }
    for (auto i : fl) 
        cout << i << " ";
}