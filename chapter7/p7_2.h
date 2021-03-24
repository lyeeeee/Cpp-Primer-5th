//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_2_H
#define C__PRIMER_P7_2_H

#include <string>
using namespace std;
struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    Sales_data& combine(const Sales_data& another);
    inline string isbn() const {return this->bookNo;}
};

Sales_data& Sales_data::combine(const Sales_data &another) {
    this->units_sold += another.units_sold;
    this->revenue += another.revenue;
    return *this;
}
#endif //C__PRIMER_P7_2_H
