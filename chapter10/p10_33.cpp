#include <algorithm>
#include <iostream>
#include <vector>
#include <list>
#include <numeric>
#include "../include/Sales_item.h"
#include <iterator>
#include <fstream>
using namespace std;




int main () {
    vector<Sales_item> v;
	istream_iterator<Sales_item> in(cin), eof;
	while (in != eof) {
		v.push_back(*in++);
	}

	sort(v.begin(), v.end(), [](const Sales_item &data1, const Sales_item &data2){return data1.isbn().compare(data2.isbn());});
	auto p = v.cbegin();
	while (p != v.cend()) {
		auto idx = find_if(p, v.cend(), [&p](const Sales_item &data){return data.isbn() != p->isbn();});
		cout << accumulate(p, idx, Sales_item(p->isbn())) << endl;
		p = idx;
	}
}