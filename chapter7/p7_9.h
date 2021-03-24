//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_9_H
#define C__PRIMER_P7_9_H

#include <string>
#include <iostream>
using namespace std;
struct Person {
    string name;
    string address;
};

ostream& print(ostream& out, const Person& person) {
    out << person.name << person.address;
}

istream& read(istream& in, Person& person) {
    in >> person.name >> person.address;
}
#endif //C__PRIMER_P7_9_H
