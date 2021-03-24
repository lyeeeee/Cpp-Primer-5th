#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include <forward_list>
using namespace std;

void replace(string& s, const string& old, const string& news) {
    for (size_t i = 0; i <= s.size() - old.size(); ++i) {
        string tmp = s.substr(i,old.size());
        if (tmp == old) {
            s.replace(i,old.size(), news);
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