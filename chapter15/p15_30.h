#include <iostream>
#include "p15_3Quote.h"
#include "p15_15Disc_quote.h"
#include "p15_15Bulk_quote.h"
#include <vector>
#include <memory>
#include <algorithm>
#include <set>s

using namespace std;

class Basket {
public:

protected:

private:
    static bool compare(shared_ptr<Quote> &l, shared_ptr<Quote> &r) {
        return l->isbn() < r->isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)> items{compare};
};