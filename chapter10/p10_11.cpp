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

bool isShorter(string const& s1, string const& s2) {
    return s1.size() < s2.size();
}
int main() {
    std::vector<std::string> vs{ "1234", "1234", "1234", "Hi", "alan", "wang" };
    for(const auto& x : vs) {
        cout << x << " ";
    }
    cout << endl;
    elimDups(vs);
    std::stable_sort(vs.begin(), vs.end(), isShorter);
    for(const auto& x : vs) {
        cout << x << " ";
    }
    cout << endl;
}