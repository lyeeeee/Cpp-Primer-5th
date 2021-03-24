#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> l;
    int buf;
    while (cin >> buf) {
        l.push_back(buf);
    }
    deque<int> dq1;
    deque<int> dq2;
    for (auto i = l.begin();i != l.end(); ++i) {
        if (*i % 2 == 0) {
            dq1.push_back(*i);
        } else {
            dq2.push_back(*i);
        }
    }
}