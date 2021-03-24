#include <iostream>
#include "../chapter2/p2_42.h"

using std::cin;
using std::cout;
using std::endl;
using std::cerr;
int main()
{
	SalesData data1, data2;

    double price = 0;  

    cin >> data1.book_no_ >> data1.units_sold_ >> price;
    
    data1.revenue_ = data1.units_sold_ * price;

    cin >> data2.book_no_ >> data2.units_sold_ >> price;
    data2.revenue_ = data2.units_sold_ * price;

    if (data1.book_no_ == data2.book_no_)
    {
        unsigned totalCnt = data1.units_sold_ + data2.units_sold_;
        double totalrevenue_ = data1.revenue_ + data2.revenue_;

        cout << data1.book_no_ << " " << totalCnt
            << " " << totalrevenue_ << " ";
        if (totalCnt != 0)
            cout << totalrevenue_ / totalCnt << endl;
        else
            cout << "(no sales)" << endl;

        return 0;  
    }
    else
    {  
        cerr << "Data must refer to the same ISBN" << endl;
        return -1; 
    }
}