//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_41_H
#define C__PRIMER_P7_41_H

#include <string>
#include <iostream>
using namespace std;

struct Sales_data;
std::istream &read(std::istream&, Sales_data&);

struct Sales_data{
    
    friend Sales_data add(Sales_data& l, Sales_data& r);
    friend istream& read(istream& in, Sales_data& data);
    friend ostream& print(ostream& out, const Sales_data& data);

    private:
        string bookNo;
        unsigned units_sold = 0;
        double revenue = 0.0;

    public:
        Sales_data& combine(const Sales_data& another);
        inline string isbn() const {return this->bookNo;}
        inline double avg_price() const;

        Sales_data(): Sales_data("", 0,0.0){
            cout << "Sales_data(): Sales_data("", 0,0.0)" << endl;
        }
        Sales_data(const string& s): Sales_data(s,0,0.0){
            cout << "Sales_data(const string& s): Sales_data(s,0,0.0)" << endl;
        }
        Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n*p){
            cout << "Sales_data(const string& s, unsigned n, double p): bookNo(s), units_sold(n), revenue(n*p)" << endl;
        }
        Sales_data(istream& in):Sales_data() {
             cout << "Sales_data(istream& in):Sales_data()" << endl;
            read(in,*this);
        }
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

inline
double Sales_data::avg_price() const{
    return units_sold ? revenue/units_sold : 0;
}

#endif //C__PRIMER_P7_41_H
