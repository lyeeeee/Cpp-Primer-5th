//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P14_2_H
#define C__PRIMER_P14_2_H
#define C__PRIMER_P14_2_H

#include <string>
#include <iostream>
using namespace std;

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{

    friend Sales_data add(Sales_data& l, Sales_data& r);
    friend istream& read(istream& in, Sales_data& data);
    friend ostream& print(ostream& out, const Sales_data& data);
    friend Sales_data operator+(Sales_data data1, Sales_data data2);
    friend istream &operator>>(istream &in, Sales_data &data);
    friend ostream &operator<<(ostream &os, Sales_data &item);
    private:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

    public:
        Sales_data& combine(const Sales_data& another);
        inline string isbn() const {return this->bookNo;}
        inline double avg_price() const;

        Sales_data(): Sales_data("", 0,0.0){
        }
        Sales_data(const string& s): Sales_data(s,0,0.0){
        }
        Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n*p){

        }
        Sales_data(istream& in):Sales_data() {
            read(in,*this);
        }

        Sales_data &operator+=(Sales_data &another) {
            units_sold += another.units_sold;
            revenue += another.revenue;
            return *this;
        }


};

Sales_data operator+(Sales_data &data1, Sales_data &data2) {
    Sales_data sum = data1;
	sum += data2;
	return sum;
}

ostream &operator<<(ostream &os, Sales_data &item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

istream &operator>>(istream &in, Sales_data &data) {
    double price = 0.0;
    in >> data.bookNo >> data.units_sold >> price;
    if (in)
        data.revenue = price * data.units_sold;
    else
        data = Sales_data();
    return in;
}

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

inline
double Sales_data::avg_price() const{
    return units_sold ? revenue/units_sold : 0;
}

#endif //C__PRIMER_P14_2_H
