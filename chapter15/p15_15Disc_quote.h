#ifndef __p15_15_DISC_QUOTE_H__
#define __p15_15_DISC_QUOTE_H__
#include <memory>
#include <iostream>
#include "p15_3Quote.h"

using std::string;
using std::cout;
using std::endl;

class Disc_quote : public  Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc): Quote(book, price), quantity(qty), discount(disc) {}
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity;
    double discount = 0.0;
};
#endif //