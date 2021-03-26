#ifndef __P15_5_H__
#define __P15_5_H__
#include <memory>
#include <iostream>
#include "p15_3Quote.h"

using std::string;

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double p, std::size_t mq, double dis):Quote(s,p), min_qty(mq), discount(dis){}

    double net_price(size_t n) const override {
        if (n < min_qty) {
            return n * price;
        } else {
            return n * (1 - discount) * price;
        }
    }
protected:

private:
    std::size_t min_qty;
    double discount;
};
#endif