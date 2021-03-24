#include "p7_11.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    Sales_data data1;
    Sales_data data2("hello");
    Sales_data data3("hello", 1, 10);
    Sales_data data4(cin);
    print(cout, data1);
    print(cout, data2);
    print(cout, data3);
    print(cout, data4);
}
