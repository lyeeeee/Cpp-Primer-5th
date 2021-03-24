#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int val;
    vector<int> iv;
    while (cin >> val) {
        iv.push_back(val);
    }
    int cnt = count(iv.cbegin(), iv.cend(), 3);
    cout << cnt << endl;
}