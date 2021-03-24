#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include "../chapter7/p7_41.h"
using namespace std;


bool compareIsbn(const Sales_data &data1, const Sales_data &data2) {
    return data1.isbn().compare(data2.isbn());
}

int main() {
    Sales_data d1("aa"), d2("aaaa"), d3("aaa"), d4("z"), d5("aaaaz");
    vector<Sales_data> ve = {d1, d2, d3, d4, d5};

    sort(ve.begin(), ve.end(), [](const Sales_data &data1, const Sales_data &data2){return data1.isbn().compare(data2.isbn());});

    for (const Sales_data &data : ve) {
        cout << data.isbn() << " ";
    }
}