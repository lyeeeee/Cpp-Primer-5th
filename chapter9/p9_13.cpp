#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    list<int> l(5, 4);
    vector<int> iv(5, 5);

    vector<double> dv(l.begin(), l.end());
    for (auto i : l) cout << i << " ";
    cout << endl;
    for (auto d : dv) cout << d << " ";
    cout << endl;


    vector<double> dv2(iv.begin(), iv.end());
    for (auto i : iv) cout << i << " ";
    cout << endl;
    for (auto d : dv2) cout << d << " ";

    return 0;
}