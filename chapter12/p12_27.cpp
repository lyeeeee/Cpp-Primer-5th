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
    for (map<string, shared_ptr<set<size_type>>>::const_iterator it = word_map.cbegin(); it != word_map.cend(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }
}

QueryResult TextQuery::query(const string word) const {
    static shared_ptr<set<size_type>> nodata(new set<size_type>);
    if (word_map.find(word) != word_map.end()) {
        cout << "find word:" << word << endl;
        auto val = word_map.find(word);
        return QueryResult(word, val->second, lines);
    } else {
        return QueryResult(word, nodata, lines);
    }
}

std::ostream& print(ostream& os, const QueryResult& qr) {
	os << qr.find << " occurs " << qr.line_numbers->size() << " "
		<< "time" << (qr.line_numbers->size() > 1 ? "s" : "") << endl;
	for (auto num : *qr.line_numbers)
		os << "\t(line " << num + 1 << ") " << *(qr.file->begin() + num) << endl;
	return os;
}