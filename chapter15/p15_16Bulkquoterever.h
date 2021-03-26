#include <memory>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

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

    virtual void debug() const;

    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price;
};

class Disc_quote : public  Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc): Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity;
    double discount = 0.0;
};

class Bulk_quote: public Disc_quote {
public:
    double net_price(size_t n) const override;

    virtual void debug() const override;
};

double print_total(std::ostream &os, const Quote &q, size_t n) {
    auto total = q.net_price(n);
    os << "ISBN:" << q.isbn()
		<< "# sold: " << n << " total due: " << total << std::endl;

	return total;
}

void Quote::debug() const {
    cout << bookNo << " " << price << endl;
}

void Bulk_quote::debug() const {

}