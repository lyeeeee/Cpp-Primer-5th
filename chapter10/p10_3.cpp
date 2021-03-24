#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    int val;
    vector<int> iv;
    while (cin >> val) {
        iv.push_back(val);
    }
    int cnt = accumulate(iv.cbegin(), iv.cend(),0);
    cout << cnt << endl;
}