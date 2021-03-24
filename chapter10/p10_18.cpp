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

void biggies(vector<string> &v, string::size_type len) {
    elims(v);

    stable_sort(v.begin(), v.end(), [](const string &a, const string &b){return a.size() < b.size();});

    //auto idx = find_if(v.begin(), v.end(), [len](const string &s){s.size()>= len;});
    auto idx = partition(v.begin(), v.end(), [len](const string &s){return s.size() < len;});
    for_each(idx, v.end(), [](const string &s){cout << s << " ";});
}

int main () {
    std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", 
		"over", "the", "slow", "red", "turtle" };

	biggies(v, 4);
	std::cout << std::endl;
	return 0;
}