//
// Created by liyi on 2020/3/26.
//

#include <iostream>
#include <string>
#include "p7_2.h"
using namespace std;

int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data tmp;
        while (cin >> tmp.bookNo >> tmp.units_sold >> tmp.revenue) {
            if (tmp.isbn() == total.isbn()) {
                total.combine(tmp);
            } else {
                cout << "book: " << total.isbn() << " "<< total.units_sold << " " << total.revenue << endl;
                total = tmp;
            }
        }
        cout << "book: " << total.isbn() << " "<< total.units_sold << " " << total.revenue << endl;
    } else {
        cout << "no data!" << endl;
        return -1;
    }
    return 0;
}
