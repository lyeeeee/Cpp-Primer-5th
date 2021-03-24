#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;




int main () {
    vector<int> v1{ 1, 1, 3, 3, 5, 5, 7, 7, 9 };
	vector<int> v2;
	unique_copy(v1.begin(), v1.end(), back_inserter(v2));

	for_each(v2.begin(), v2.end(), [](int i){cout << i << endl;});
}