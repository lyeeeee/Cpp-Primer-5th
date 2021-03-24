//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_6_H
#define C__PRIMER_P7_6_H

#include <string>
#include <iostream>
using namespace std;

struct Sales_data{
    inline std::string isbn() const { return this->bookNo;}
    Sales_data &combine(const Sales_data &data);
    double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
    
};

double Sales_data::avg_price() const {
    if (units_sold) {
        return this->revenue/this->units_sold;
    } else return 0.0;
}

Sales_data &Sales_data::combine(const Sales_data &data) {
    this->units_sold += data.units_sold;
    this->revenue += data.revenue;
    return *this;
}

istream &read(istream &is, Sales_data &data) {
    double price = 0;
    is >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold * price;
    return is;
}

ostream &print(ostream &os, Sales_data &data) {
    os << data.isbn() << " " << data.units_sold << " " << data.revenue << " " << data.avg_price();
    return os;
}
#endif //C__PRIMER_P7_6_H
