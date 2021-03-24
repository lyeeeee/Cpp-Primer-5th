//
// Created by liyi on 2020/3/26.
//

#include <iostream>
#include <string>
using namespace std;

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
int main() {
    Sales_data total;
    if (cin >> total.bookNo >> total.units_sold >> total.revenue) {
        Sales_data tmp;
        while (cin >> tmp.bookNo >> tmp.units_sold >> tmp.revenue) {
            if (tmp.bookNo == total.bookNo) {
                total.units_sold += tmp.units_sold;
                total.revenue += tmp.revenue;
            } else {
                cout << "book: " << total.bookNo << " "<< total.units_sold << " " << total.revenue << endl;
                total = tmp;
            }
        }
        cout << "book: " << total.bookNo << " "<< total.units_sold << " " << total.revenue << endl;
    } else {
        cout << "no data!" << endl;
        return -1;
    }
    return 0;
}
