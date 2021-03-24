//
// Created by liyi on 2020/4/3.
//

#ifndef C__PRIMER_P7_32_H
#define C__PRIMER_P7_32_H

#include <vector>
#include <string>
#include <iostream>

class Window_mgr;

class Screen {

public:

    friend void Window_mgr;
public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos h,pos w, char c):height(h), width(w), contents(h*w, c) {}
    Screen(pos h, pos w): height(h), width(w), contents(h*w,' '){}

    char get() const {return contents[cursor];}
    char get(pos r, pos c) const {return contents[r*width+c];}

    Screen &set(char c) {
        contents[cursor] = c;
        return *this;
    }

    Screen &set(pos h, pos w, char c) {
        contents[h*width + w] = c;
        return *this;
    }

    inline Screen& move(pos r, pos c);

    Screen &display(std::ostream &os) {
        do_display(os);
        return *this;
    }

    const Screen &display(std::ostream &os) const {
        do_display(os);
        return *this;
    }

private:
    void do_display(std::ostream &os) const {os << contents;}
private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

void Window_mgr::clear(ScreenIndex idx) {
    Screen &s = screens[idx];
    s.contents = std::string(s.height*s.width, ' ');
}


class Window_mgr {

public:
    using ScreenIndex = std::vector<Screen>::size_type;
    void clear(ScreenIndex);
private:
    std::vector<Screen> screens;
};



inline
Screen& Screen::move(pos r, pos c) {
    cursor = r*width + c;
    return *this;
}
#endif //C__PRIMER_P7_32_H
