#ifndef __15_3_QUOTE_H__
#define __15_3_QUOTE_H__
#include <memory>
#include <iostream>

using std::string;

using namespace std;

class Quote {
public:
    Quote() = default;

    Quote(const string &b, double p): bookNo(b), price(p){}

    string isbn() const { return bookNo;}

    virtual double net_price(size_t n) const { return n * price; }

    virtual void debug() const {
        cout << "bookNo: " << bookNo << " price: " << price << endl;
    }

    virtual ~Quote() = default;
private:
    string bookNo;

protected:
    double price = 0.0;
};

double print_total(ostream &os, const Quote &q, size_t n) {
    double ret = q.net_price(n);
    os << "ISBN: " << q.isbn() << " total cost:" << ret << endl;
    return ret;
}
#endif