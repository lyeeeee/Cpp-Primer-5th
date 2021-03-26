#ifndef __P15_7_H__
#define __P15_7_H__
#include <memory>
#include <iostream>
#include "p15_3Quote.h"

using std::string;

class Bulk_quote_rever: public Quote {
public:
    Bulk_quote_rever() = default;
    Bulk_quote_rever(const string &s, double p, std::size_t mq, double dis):Quote(s,p), max_qty(mq), discount(dis){}

    double net_price(size_t n) const override {
        if (n > max_qty) {
            return max_qty * price + (n - max_qty)*price * (1-discount);
        } else {
            return n * price;
        }
    }
protected:

private:
    std::size_t max_qty;
    double discount;
};
#endif