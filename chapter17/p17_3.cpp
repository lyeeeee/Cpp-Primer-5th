#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>

using namespace std;
using std::make_tuple;

TextQuery::TextQuery(ifstream &ifs) : lines(new vector<string>) {
    string s;
    while (getline(ifs, s)) {
        lines->push_back(s);
        istringstream iss(s);
        int line_n = lines->size()-1;
        string word;
        while (iss >> word) {
            auto &nums = word_map[word];
            if (!nums) {
                nums.reset(new set<size_type>);
            }
            nums->insert(line_n);
        }
    }
}

tuple<string, shared_ptr<set<TextQuery::size_type>>, vector<string>> TextQuery::query(const string word) const {
    static shared_ptr<set<size_type>> nodata(new set<size_type>);
    if (word_map.find(word) != word_map.end()) {
        auto val = word_map.find(word);
        return tuple<string, shared_ptr<set<TextQuery::size_type>>, vector<string>>(word, val->second, lines);
    } else {
        return {word, nodata, lines};
    }
}

std::ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.find << " occurs " << qr.line_numbers->size() << " "
		<< "time" << (qr.line_numbers->size() > 1 ? "s" : "") << endl;
	for (auto num : *qr.line_numbers)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}