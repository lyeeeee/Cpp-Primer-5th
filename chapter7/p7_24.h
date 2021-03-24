//
// Created by liyi on 2020/4/3.
//

#ifndef C__PRIMER_P7_24_H
#define C__PRIMER_P7_24_H

#include <string>
#include <iostream>
class Screen {
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos h,pos w, char c):height(h), width(w), contents(h*w, c) {}
    Screen(pos h, pos w): height(h), width(w), contents(h*w,' '){}

    char get() const {
        return contents[cursor];
    }

    char get(pos r, pos c) const {
        return contents[r*width+c];
    }

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};
#endif //C__PRIMER_P7_24_H
