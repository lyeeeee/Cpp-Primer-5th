//
// Created by liyi on 2020/3/26.
//

#include <iostream>
#include <string>
#include "p7_6.h"
using namespace std;

int main() {
    Sales_data total;
    if (read(cin, total)) {
        Sales_data tmp;
        while (read(cin, tmp)) {
            if (tmp.isbn() == total.isbn()) {
                total.combine(tmp);
            } else {
                print(cout, total);
                total = tmp;
            }
        }
        print(cout, total);
    } else {
        cout << "no data!" << endl;
        return -1;
    }
    return 0;
}
