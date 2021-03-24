#ifndef _P13_18_H_
#define _P13_18_H_
#include <iostream>
#include <vector>
#include <initializer_list>

class Employee {

public:
    Employee() = default;
    Employee(std::string &n) {
        name = n;
        no = num++;
    }

    std::string name;
    int no;

    static int num;
};

#endif
// 会输出 a、b、c的数。