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
    HasPtr(const string &s = string()) : ps(new string(s)), i(0){}

    HasPtr(const HasPtr & obj) : ps(obj.ps), i(obj.i){
    }

    HasPtr& operator=(const HasPtr &obj) {
        delete ps;
        ps = obj.ps;
        i = obj.i;
        return *this;
    }

    HasPtr(HasPtr &&h) noexcept{
        ps = h.ps;
        i = h.i;
        h.ps = nullptr;
    }

    HasPtr& operator=(HasPtr h) {
        swap(*this, h);
        return *this;
    }

    HasPtr& operator=(HasPtr &&h) noexcept{
        delete ps;
        ps = h.ps;
        i = h.i;
        h.ps = nullptr;
        return *this;
    }

    bool operator<(const HasPtr &h) {
        return *(this->ps) < *h.ps;
    }

    ~HasPtr() {
        delete ps;
    }

    void show() const
	{
		std::cout << *ps << std::endl;
	}
private:
    string *ps;
    int i;
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