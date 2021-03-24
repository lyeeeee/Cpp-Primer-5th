#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;

void findAndInsert(forward_list<string>& fl, string& s1, string& s2){
    auto pre = fl.before_begin();
    auto i = fl.begin();
    while (i != fl.end()) {
        if (*i == s1) {
            fl.insert_after(i, s2);
            return;
        } else {
            i++;
            pre++;
        }
    }
    if (i == fl.end()) {
        fl.insert_after(pre, s2);
    }
}
int main() {
    forward_list<string> fl = {"hello", "world"};
    string s1 = "x";
    string s2 = "a";
    findAndInsert(fl, s1, s2);
    for (const auto &s : fl) {
        cout << s << endl;
    }
}