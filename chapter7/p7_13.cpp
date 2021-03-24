//
// Created by liyi on 2020/3/26.
//

#include <iostream>
#include <string>
#include "p7_12.h"
using namespace std;

int main() {
    Sales_data total(cin);
    if (!total.isbn().empty()) {
        istream& in = cin;
        while (in) {
            Sales_data tmp(in);
            if (!in) break;
            if (tmp.isbn() == total.isbn()) {
                total.combine(tmp);
            } else {
                print(cout, total);
                total = tmp;
            }
        }
        print(cout, total);
    } else {
        cout << "no data!" << endl;
        return -1;
    }
    return 0;
}
