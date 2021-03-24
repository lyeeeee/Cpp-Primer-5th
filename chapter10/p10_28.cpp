#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include "../chapter7/p7_41.h"
#include <iterator>
using namespace std;




int main () {
    vector<int> v1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	list<int> v2, v3, v4;
	copy(v1.cbegin(), v1.cend(), inserter(v2, v2.begin()));
	copy(v1.cbegin(), v1.cend(), back_inserter(v3));
	copy(v1.cbegin(), v1.cend(), front_inserter(v4));
}