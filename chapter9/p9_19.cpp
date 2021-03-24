#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<string> l;
    string buf;
    while (cin >> buf) {
        l.push_back(buf);
    }
    for (const auto& s : l) {
        cout << s << endl;
    }
    return 0;
}