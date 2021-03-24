#include <iostream>
#include <string>
#include <fstream>
#include "../chapter7/p7_41.h"
using namespace std;

int main(int argc, char* argv[]) {
    Sales_data total;
    ifstream in("./inputfile");
    ofstream out("./outputfile", ofstream::app);
    if (!out.good()) {
        return -1;
    }
    if (!in) {
        return -1;
    }
    if (read(in, total)) {
        Sales_data tmp;
        while (read(in, tmp)) {
            if (tmp.isbn() == total.isbn()) {
                total.combine(tmp);
            } else {
                print(out, total);
                total = tmp;
            }
        }
        print(out, total);
    } else {
        cout << "no data!" << endl;
        return -1;
    }
    return 0;
}