#include <iostream>
#include <string>
#include <vector>
#include "p9_51.h"
using namespace std;



int main() {
    Date data1("January 1,1990");
    Date data2("January 1 1990");
    Date data3("1/1/1990");
    cout << data1.year << " " << data1.month << " " << data1.day << endl;
    cout << data2.year << " " << data2.month << " " << data2.day << endl;
    cout << data3.year << " " << data3.month << " " << data3.day << endl;
    return 0;
}