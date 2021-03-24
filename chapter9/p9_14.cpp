#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<char*> l = {"hello", "world"};
    vector<string> v(l.begin(), l.end());
    for (const auto& s: v) {
        cout << s << endl;
    }
}