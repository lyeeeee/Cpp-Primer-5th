#ifndef __P16_21_H__
#define __P16_21_H__
#include <memory>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class DebugDelete {
public:
    DebugDelete(std::ostream &o = std::cerr): os(o){}

    template<typename T>
    void operator()(T *p) const {
      cout << "deleting unique_ptr " << endl;
      delete p;
    }
private:
    std::ostream &os;
};
#endif