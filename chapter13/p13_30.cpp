#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include <cstring>

using std::string;

class HasPtr {
public:
    friend void swap(HasPtr & h1, HasPtr & h2);
    HasPtr(const string &s = string()) : ps(new string(s)), i(0), ref_cnt(new size_t(1)){}
    HasPtr(const HasPtr & obj) : ps(obj.ps), i(obj.i), ref_cnt(obj.ref_cnt) {
        (*ref_cnt)++;
    }

    HasPtr& operator=(const HasPtr &obj) {
        ++(*(obj.ref_cnt));
        if (--(*ref_cnt) == 0) {
            delete ps;
            delete ref_cnt;
        }
        ps = obj.ps;
        i = obj.i;
        ref_cnt = obj.ref_cnt;
        return *this;
    }

    ~HasPtr() {
        if (--(*ref_cnt) == 0) {
            delete ps;
            delete ref_cnt;
        }
    }
private:
    string *ps;
    int i;
    size_t *ref_cnt;
};

void swap(HasPtr & h1, HasPtr & h2) {
    using std::swap;
    swap(h1.ps, h2.ps);
    swap(h1.i, h2.i);
    swap(h1.ref_cnt, h2.ref_cnt);
    cout << "call swap" << endl;
}
int main() {
    HasPtr h1("hello");
    HasPtr h2("world");
    swap(h1, h2);
}