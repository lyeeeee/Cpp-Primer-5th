//
// Created by liyi on 2020/4/3.
//

#ifndef C__PRIMER_P7_33_H
#define C__PRIMER_P7_33_H

#include <vector>
#include <string>
#include <iostream>

class Screen;

class Window_mgr{
public:
    using Screen_idx = std::vector<Screen>::size_type;
    inline void clear(Screen_idx);

private:
    std::vector<Screen> screens;
};

inline
void Window_mgr::clear(Screen_idx idx) {
    if (idx >= screens.size()) return;
    Screen& screen = screens[idx];
    screen.contents = std::string(screen.width*screen.height, ' ');
}

class Screen {
    friend void Window_mgr::clear(Screen_idx idx);

public:
    using pos = std::string::size_type;

    Screen() = default;
    Screen(pos h,pos w, char c):height(h), width(w), contents(h*w, c) {}
    Screen(pos h, pos w): height(h), width(w), contents(h*w,' '){}

    char get() const {return contents[cursor];}
    char get(pos r, pos c) const {return contents[r*width+c];}

    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream& out) const {do_display(out); return *this;}
    Screen& display(std::ostream& out) {do_display(out); return *this;}
    pos size() const;
private:
    void do_display(std::ostream& out) const {out << contents;}

private:
    pos cursor = 0;
    pos height = 0, width = 0;
    std::string contents;
};

inline
Screen& Screen::set(char c) {
    contents[cursor] = c;
    return *this;
}

inline
Screen& Screen::set(pos r, pos c, char ch) {
    contents[r*width+c] = ch;
    return *this;
}

inline
Screen& Screen::move(pos r, pos c) {
    cursor = r*width + c;
    return *this;
}

Screen::pos Screen::size() const {
    return height*width;
}
#endif //C__PRIMER_P7_33_H
