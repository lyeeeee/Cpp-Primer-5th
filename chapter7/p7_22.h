//
// Created by liyi on 2020/4/2.
//

#ifndef C__PRIMER_P7_9_H
#define C__PRIMER_P7_9_H

#include <string>
#include <iostream>
using namespace std;

struct Person;
istream& read(istream& in, Person& person);
ostream& print(ostream& out, const Person& person);

struct Person {
    friend ostream& print(ostream& out, const Person& person);
    friend istream& read(istream& in, Person& person);
    private:
        string name;
        string address;

    public:
        Person() = default;
        Person(const string& n, const string& add): name(n), address(add){}
        Person(istream& in) {read(in, *this);}
};

ostream& print(ostream& out, const Person& person) {
    out << person.name << person.address;
}

istream& read(istream& in, Person& person) {
    in >> person.name >> person.address;
}
#endif //C__PRIMER_P7_9_H
