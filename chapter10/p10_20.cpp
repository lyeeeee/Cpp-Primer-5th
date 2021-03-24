#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;




int main () {
    std::vector<std::string> v{ "the", "quick", "red", "fox", "jumps", 
		"over", "the", "slow", "red", "turtle" };

	auto cnt = count_if(v.begin(), v.end(), [](const string &s) -> bool {return s.size() >= 6;});
	std::cout << cnt << std::endl;
	return 0;
}