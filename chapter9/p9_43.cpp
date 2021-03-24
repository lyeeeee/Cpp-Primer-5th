#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;

void replace(string& s, const string& old, const string& news) {
    for (auto i = s.begin(); i <= s.end() - old.size(); ++i) {
        string tmp(i, i+old.size());
        if (tmp == old) {
            s.erase(i, i+old.size());
            s.insert(i, news.begin(), news.end());
            i += news.size();
            i--;
        }
    }
}

int main() {
    string s{ "To drive straight thru is a foolish, tho courageous act." };
    replace(s, "tho", "though");
    replace(s, "thru", "through");
    cout << s << endl;

    return 0;
}