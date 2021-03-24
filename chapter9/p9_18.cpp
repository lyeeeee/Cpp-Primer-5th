#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    deque<string> dq;
    string buf;
    while (cin >> buf) {
        dq.push_back(buf);
    }
    for (const auto& s : dq) {
        cout << s << endl;
    }
    return 0;
}