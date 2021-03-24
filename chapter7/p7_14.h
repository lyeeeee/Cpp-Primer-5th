//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_11_H
#define C__PRIMER_P7_11_H

#include <string>
#include <iostream>
using namespace std;

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

    Sales_data& combine(const Sales_data& another);
    inline string isbn() const {return this->bookNo;}
    Sales_data() = default;
    Sales_data(const string& s): bookNo(s){}
    Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n*p){}
    Sales_data(istream& in) {read(in,*this);}  
    Sales_data() : units_sold(0) , revenue(0) { }
};

Sales_data& Sales_data::combine(const Sales_data &another) {
    this->units_sold += another.units_sold;
    this->revenue += another.revenue;
    return *this;
}
Sales_data add(Sales_data& l, Sales_data& r){
    Sales_data total = l;
    total.combine(r);
    return total;
}
istream& read(istream& in, Sales_data& data){
    double price;
    in >> data.bookNo >> data.units_sold >> price;
    data.revenue = data.units_sold*price;
    return in;
}
ostream& print(ostream& out, const Sales_data& data){
    out << data.isbn() << " " << data.units_sold << " " << data.revenue;
    return out;
}


#endif //C__PRIMER_P7_11_H
