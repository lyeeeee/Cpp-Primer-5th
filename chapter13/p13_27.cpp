#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), use(new size_t(1)){}

    HasPtr(const HasPtr & h) {
        ps = h.ps;
        i = h.i;
        use = h.use;
        ++*use;
    }

    HasPtr& operator=(const HasPtr &h) {
        ++*h.use;
        --*use;
        if (*use == 0) {
            delete ps;
            delete use;
        }

        ps = h.ps;
        i = h.i;
        use = h.use;
        return *this;
    }
private:
    string *ps;
    int i;
    std::size_t *use;
};