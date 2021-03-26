#include <iostream>
#include "p15_3Quote.h"
#include "p15_15Disc_quote.h"
#include "p15_15Bulk_quote.h"
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    vector<shared_ptr<Quote>> quotes = {
        make_shared<Bulk_quote>(Bulk_quote("1", 1, 1, 1)),
        make_shared<Bulk_quote>(Bulk_quote("2", 2, 2, 2)),
        make_shared<Bulk_quote>(Bulk_quote("3", 3, 3, 3)),
    };

    for_each(quotes.cbegin(), quotes.cend(), [](const shared_ptr<Quote> &q){cout << (*q).net_price(2) << endl; });
}