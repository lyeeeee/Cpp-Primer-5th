#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    map<string, size_t> map;
    string word;

    while (cin >> word) {
        map[word]++;
    }
    for (const auto &w : map) {
        cout << w.first << " count:" << w.second << endl; 
    }
}