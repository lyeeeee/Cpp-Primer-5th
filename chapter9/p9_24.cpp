#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    vector<int> v;
    cout << *v.begin() << endl;
    cout << v.at(0) << endl;
    cout << v[0] << endl;
    cout << v.front() << endl;
}