#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"

using std::string;
using std::cout;
using std::endl;
template <typename T>
int compare(const T& a, const T& b) {
    if (a < b) return -1;
    else if (b < a) return 1;
    return 0;
}


int main() {
    Sales_data d1("hello", 1, 10);
    Sales_data d2("world",2 ,20);
    cout << compare(d1, d2) << endl;
}