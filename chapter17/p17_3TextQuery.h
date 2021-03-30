#ifndef _P12_27_H_
#define _P12_27_H_
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class QueryResult;

class TextQuery {
public:
    typedef vector<string>::size_type size_type;
public:
    TextQuery(ifstream &ifs);

    tuple<string, shared_ptr<set<TextQuery::size_type>>, shared_ptr<vector<string>>> query(const string word) const;
private:
    shared_ptr<vector<string>> lines;
    map<string, shared_ptr<set<size_type>>> word_map;
};

// class QueryResult {
// public:
//     friend ostream& print(ostream& out, const QueryResult& qr);
// public:
//     QueryResult(const string word, shared_ptr<set<TextQuery::size_type>> p, shared_ptr<vector<string>> f) : find(word), line_numbers(p), file(f){};

// private:
//     string find;
//     shared_ptr<set<TextQuery::size_type>> line_numbers;
//     shared_ptr<vector<string>> file;
// };

#endif