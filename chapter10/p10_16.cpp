#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;


void elims(vector<string> &v) {
    sort(v.begin(), v.end());
    auto idx = unique(v.begin(), v.end());
    v.erase(idx, v.end());
}

void biggies(vector<string> &v, size_t len) {
    elims(v);

    stable_sort(v.begin(), v.end(), [](string const &a, string const &b){ return a.size() < b.size();});

    auto idx = find_if(v.begin(), v.end(), [len](string const &s){ return s.size()>= len;});
    for_each(idx, v.end(), [](const string &s){cout << s << " ";});
}

int main () {
    std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", 
		"over", "the", "slow", "red", "turtle" };

	biggies(v, 3);
	std::cout << std::endl;
	return 0;
}