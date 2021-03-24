#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

void elimDups(vector<string>& v) {
    sort(v.begin(), v.end());
    auto end = unique(v.begin(), v.end());
    v.erase(end, v.end());
}
int main() {
    std::vector<std::string> vs{ "a", "v", "a", "s", "v", "a", "a" };
    for(const auto& x : vs) {
        cout << x << endl;
    }
    elimDups(vs);
    for(const auto& x : vs) {
        cout << x << endl;
    }
}