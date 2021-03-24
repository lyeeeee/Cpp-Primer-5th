#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;


int main() {
    forward_list<string> fl = {"hello", "world"};
    auto beg = fl.begin();
    while (beg != fl.end()) {
        beg = fl.insert_after(beg,"1");
        beg++;
    }
    for (const auto& s : fl) {
        cout << s << endl;
    }
}