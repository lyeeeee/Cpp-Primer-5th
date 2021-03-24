//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_5_H
#define C__PRIMER_P7_5_H

#include <string>
using namespace std;
struct Person {
    string name;
    string address;
    inline string name() const {return this->name;}
    inline string address() const {return this->address;}
};
#endif //C__PRIMER_P7_5_H
