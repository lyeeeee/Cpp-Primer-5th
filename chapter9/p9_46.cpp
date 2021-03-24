#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;

string& change(string& s, const string& pre, const string& end) {
    s.insert(s.size(), end);
    s.insert(0, pre);
    return s;
}
int main() {
    string s = "hello";
    s = change(s, "1", "2");
    cout << s << endl;
}