#ifndef _P13_42_H_
#define _P13_42_H_
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
#include "p13_40.h"

using namespace std;

class QueryResult;

class StrVec;

class TextQuery {
public:
    typedef vector<string>::size_type size_type;
public:
    TextQuery(ifstream &ifs);

    QueryResult query(const string word) const;
private:
    shared_ptr<StrVec> lines;
    map<string, shared_ptr<set<size_type>>> word_map;
};

class QueryResult {
public:
    friend ostream& print(ostream& out, const QueryResult& qr);
public:
    QueryResult(const string word, shared_ptr<set<TextQuery::size_type>> p, shared_ptr<StrVec> f) : find(word), line_numbers(p), file(f){};

private:
    string find;
    shared_ptr<set<TextQuery::size_type>> line_numbers;
    shared_ptr<StrVec> file;
};

#endif