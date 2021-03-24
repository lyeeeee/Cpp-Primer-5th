#include <vector>
#include <deque>
#include <list>
#include <iostream>
using namespace std;

int main() {
    int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };

    vector<int> v(ia, end(ia));
    list<int> l(v.begin(), v.end());
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (*i % 2 == 0) {
            i = v.erase(i);
            i--;
        }
    }
    for (auto i = l.begin(); i != l.end(); ++i) {
        if (*i % 2 == 1) {
            i = l.erase(i);
            i--;
        }
    }
    cout << "list : ";
    for(auto i : l)   cout << i << " ";
    cout << "\nvector : ";
    for(auto i : v)   cout << i << " ";
    cout << std::endl;
}