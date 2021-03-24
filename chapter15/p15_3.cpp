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
    virtual double net_price(size_t n) const override;
};

double print_total(std::ostream &os, const Quote &q, size_t n) {
    auto total = q.net_price(n);
    os << "ISBN:" << q.isbn()
		<< "# sold: " << n << " total due: " << total << std::endl;

	return total;
}