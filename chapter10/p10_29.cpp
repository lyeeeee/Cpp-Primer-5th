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
    ifstream ifs("D:/develop/clionprojects/c++primer/chapter10/p10_29.cpp");
	istream_iterator<string> in(ifs), eof;
	vector<string> v;
	copy(in, eof, back_inserter(v));
	copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\n"));
}