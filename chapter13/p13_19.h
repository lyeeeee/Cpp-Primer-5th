#ifndef _P13_19_H_
#define _P13_19_H_
#include <iostream>
#include <vector>
#include <initializer_list>

// 需要，如果不自定义， 那么会无法控制唯一的证号

class Employee {

public:
    Employee() = default;
    Employee(std::string &n) {
        name = n;
        no = num++;
    }

    Employee(const Employee & e) {
        name = e.name;
        no = num++;
    }

    Employee& Employee::operator=(const Employee &e) {
        name = e.name;
        no = num++;
    }

    std::string name;
    int no;

    static int num;
};

#endif