#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int main() {
    vector<int> iv = {1,2,3,4,5,6};
    fill_n(iv.begin(), iv.size(), 0);
    for (const int& i : iv) {
        cout << i << endl;
    }
}