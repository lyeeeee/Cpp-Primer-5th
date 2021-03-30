#include <iostream>
#include "../chapter14/p14_45Sales_data.h"
#include <vector>
#include <algorithm>
#include <tuple>
using std::string;
using std::vector;
using std::tuple;
using std::pair;

typedef pair<vector<vector<Sales_data>>::size_type,
                pair<vector<Sales_data>::const_iterator, vector<Sales_data>::const_iterator>> match;

bool compareIsbn(const Sales_data& a, const Sales_data&b) {
    return a.isbn() < b.isbn();
}

vector<match> findbook(const vector<vector<Sales_data>> &files, const string &book) {
    vector<match> ret;

    for (auto it = files.cbegin(); it != files.cend(); ++it) {
        auto find = std::equal_range(it->cbegin(), it->cend(), Sales_data(book), compareIsbn);
        if (find.first != find.second) {
            ret.push_back(std::make_pair(it - files.cbegin(),std::make_pair( find.first, find.second)));
        }
    }
    return ret;
}

int main() {
    Sales_data data1("1", 1, 10);
    Sales_data data2("hello", 1, 10);
    Sales_data data3("1", 1, 10);
    Sales_data data4("hello", 1, 10);
    Sales_data data5("1", 1, 10);
    Sales_data data6("1", 1, 10);
    Sales_data data7("1", 1, 10);
    Sales_data data8("1", 1, 10);
    Sales_data data9("hello", 1, 10);
    vector<Sales_data> v1 = {data1, data2, data3};
    vector<Sales_data> v2 = {data4, data5, data6};
    vector<Sales_data> v3 = {data7, data8, data9};
    vector<vector<Sales_data>> data = {v1, v2, v3};
    vector<match> ret = findbook(data, "hello");
    for (auto i = ret.begin(); i != ret.end(); ++i) {
        cout << i->first << " ";
        for (auto j = (i->second.first); j != (i->second.second); ++j) {
            cout << *j << endl;
        }
    }
}