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
    friend void swap(HasPtr& h1, HasPtr& h2);
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

    bool operator<(const HasPtr &h) {
        return *(this->ps) < *h.ps;
    }

    ~HasPtr() {
        if (--(*ref_cnt) == 0) {
            delete ps;
            delete ref_cnt;
        }
    }

    void show() const
	{
		std::cout << *ps << std::endl;
	}
private:
    string *ps;
    int i;
    size_t *ref_cnt;
};

void swap(HasPtr &h1, HasPtr &h2) {
    {
        using std::swap;
        swap(h1.i, h2.i);
        swap(h1.ps, h2.ps);
        std::cout << "swap(HasPtr &h1, HasPtr &h2)" << std::endl;
    }
}


int main() {
    std::vector<HasPtr> v;
    v.push_back(HasPtr("d"));
    v.push_back(HasPtr("a"));
    v.push_back(HasPtr("b"));
    sort(v.begin(), v.end());
    for_each(v.begin(), v.end(), [](const HasPtr & obj){obj.show();});
}