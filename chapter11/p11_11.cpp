#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>
#include "include/Sales_item.h"

using namespace std;

int main() {
    using compare = bool (*)(Sales_item &data1, Sales_item &data2);
    multiset<Sales_item, compare> ms;
}