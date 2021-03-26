#ifndef __p15_15_BULK_QUOTE_H__
#define __p15_15_BULK_QUOTE_H__
#include <memory>
#include <iostream>
#include "p15_15Disc_quote.h"

using std::string;
using std::cout;
using std::endl;


class Bulk_quote: public Disc_quote {
    public:
    Bulk_quote() = default;
    Bulk_quote(const string &s, double p, std::size_t mq, double dis):Disc_quote(s, p, mq, dis){}

    double net_price(size_t n) const override {
        if (n < quantity) {
            return n * price;
        } else {
            return n * (1 - discount) * price;
        }
    }

    virtual Bulk_quote* clone() const & {
        return new Bulk_quote(*this);
    }

    virtual Bulk_quote* clone() const && {
        return new Bulk_quote(std::move(*this));
    }
};
#endif
