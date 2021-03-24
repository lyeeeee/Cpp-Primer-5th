#include "p7_41.h"
#include <iostream>

using namespace std;
int main() {
    Sales_data data1;
    cout << "===========================" << endl;
    Sales_data data2("hello");
    cout << "===========================" << endl;
    Sales_data data3("hello",1,10);
    cout << "===========================" << endl;
    Sales_data data4(cin);
}