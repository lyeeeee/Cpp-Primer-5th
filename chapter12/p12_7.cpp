#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;


shared_ptr<vector<int>> alloc_vector() {
    return make_shared<vector<int>>();
}

void read(shared_ptr<vector<int>> v) {
    int i;
    while (cin >> i) {
        v->push_back(i);
    }
}

void print(shared_ptr<vector<int>> v) {
    for_each(v->begin(), v->end(), [](const int i){cout << i << " ";});
    cout << endl;
}
int main() {
    // size_type是一个无符号类型，传入负数的时候会转换为正数
    shared_ptr<vector<int>> p = alloc_vector();
    read(p);
    print(p);
}