//
// Created by liyi on 2020/4/3.
//

#ifndef C__PRIMER_P7_23_H
#define C__PRIMER_P7_23_H

#include <string>
#include <iostream>
class Screen {
public:
    using pos = std::string::size_type;

public:
    Screen() = default;
    Screen(pos w, pos h, char c) : height(h), width(w), content(w*h,c){}

    inline char get() const {
        return content[cur];
    }

    inline char get(pos r, pos c) const;

    Screen &move(pos r, pos c);
private:
    std::string content;
    pos width, height;
    pos cur;
};

Screen &Screen::move(pos r, pos c) {
    cur = r * width + c;
    return *this;
}
char Screen::get(pos r, pos c) const {
    pos row = r*width;
    pos p = row + c;
    return content[p];
}


#endif //C__PRIMER_P7_23_H
