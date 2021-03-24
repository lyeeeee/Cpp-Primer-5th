#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include "../chapter7/p7_41.h"
#include <iterator>
#include <fstream>
using namespace std;




int main () {
    istream_iterator<int> in(cin), eof;
	vector<int> v;
	while (in != eof) {
		v.push_back(*in++);
	}

	sort(v.begin(), v.end());
	unique_copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}