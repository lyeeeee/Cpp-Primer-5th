#ifndef __P15_5_H__
#define __P15_5_H__
#include <memory>
#include <iostream>

using std::string;

class Quote {

public:
    Quote() = default;
    Quote(const string& book, double p): bookNo(book), price(p){

    }

    string isbn() const {
        return bookNo;
    }
    virtual double net_price(size_t n) const {
        return price*n;
    }

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price;
};

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t m, double dis): Quote(book,p), min_qty(m), discount(dis){}
    virtual double net_price(size_t n) const override;

private:
    size_t min_qty;
    double discount;
};

double Bulk_quote::net_price(size_t n) const {
    if (n < min_qty) return n * price;
    else return n*(1-discount)*price;
}

double print_total(std::ostream &os, const Quote &q, size_t n) {
    auto total = q.net_price(n);
    os << "ISBN:" << q.isbn()
		<< "# sold: " << n << " total due: " << total << std::endl;

	return total;
}

#endif