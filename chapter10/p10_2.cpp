#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string val;
    vector<string> iv;
    while (cin >> val) {
        iv.push_back(val);
    }
    int cnt = count(iv.cbegin(), iv.cend(), "a");
    cout << cnt << endl;
}