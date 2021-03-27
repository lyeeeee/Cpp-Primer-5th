//
// Created by liyi on 2020/4/3.
//

#ifndef C__PRIMER_P7_33_H
#define C__PRIMER_P7_33_H

#include <vector>
#include <string>
#include <iostream>

template <unsigned H, unsigned W>
class Screen {

    friend std::ostream& operator<<(std::ostream& os, const Screen<H,W> &screen);

    friend std::istream& operator>>(std::istream& in, Screen<H,W> &screen);
public:


    typedef std::string::size_type pos;
    Screen() = default;
    Screen(char c):height(H), width(W), contents(H*W,c){}

    char get() const {return contents[cursor];}
    char get(pos r, pos c) const {return contents[r*width+c];}

    inline Screen& move(pos r, pos c);
    inline Screen& set(char c);
    inline Screen& set(pos r, pos c, char ch);

    const Screen& display(std::ostream& out) const {do_display(out); return *this;}
    Screen& display(std::ostream& out) {do_display(out); return *this;}

    friend std::ostream & operator<< (std::ostream &os, const Screen<H, W> & c)
	{
		unsigned int i, j;
		for (i = 0; i<c.height; i++)
		{
			os << c.contents.substr(0, W) << std::endl;
		}
		return os;
	}

	friend std::istream & operator>> (std::istream &is, Screen &  c)
	{
		char a;
		is >> a;
		std::string temp(H*W, a);
		c.contents = temp;
		return is;
	}

private:
    void do_display(std::ostream& out) const {out << contents;}

private:
    pos cursor;
    pos height = H;
    pos width = W;
    std::string contents;
};


template <unsigned H, unsigned W>
inline
Screen<H,W>& Screen<H,W>::set(char c) {
    contents[cursor] = c;
    return *this;
}

template <unsigned H, unsigned W>
inline
Screen<H,W>& Screen<H,W>::set(pos r, pos c, char ch) {
    contents[r*width+c] = ch;
    return *this;
}

template <unsigned H, unsigned W>
inline
Screen<H,W>& Screen<H,W>::move(pos r, pos c) {
    cursor = r*width + c;
    return *this;
}
#endif //C__PRIMER_P7_33_H
