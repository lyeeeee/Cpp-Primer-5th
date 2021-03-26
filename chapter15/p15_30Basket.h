#ifndef __P15_30BASKET_H__
#define __P15_30BASKET_H__
#include <iostream>
#include "p15_3Quote.h"
#include "p15_15Disc_quote.h"
#include "p15_15Bulk_quote.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <set>

using namespace std;

class Basket {

public:
    // void add_item(const std::shared_ptr<Quote> &q) {
    //     items.insert(q);
    // }
    void add_item(const Quote &q) {
        items.insert(shared_ptr<Quote>(q.clone()));
    }

    void add_item(const Quote &&q) {
        items.insert(shared_ptr<Quote>(q.clone()));
    }

    double total_receipt(ostream &os) const {
        double sum = 0.0;
        for (auto item = items.cbegin(); item != items.cend(); item = items.upper_bound(*item)) {
            sum += print_total(os, **item, items.count(*item));
        }
        os << "Total: " << sum << endl;
        return sum;
    }

private:
    static bool compare(shared_ptr<Quote> &l, shared_ptr<Quote> &r) {
        return l->isbn() < r->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)> items{compare};
};
#endif