#ifndef __P13_40_H__
#define __P13_40_H__
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
using std::allocator;
using std::pair;
class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr){}
    StrVec(std::initializer_list<string> li): elements(nullptr), first_free(nullptr), cap(nullptr){
        auto data = alloc_n_copy(li.begin(), li.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    StrVec(const StrVec &s);
    StrVec& operator=(const StrVec &);

    StrVec(StrVec &&s) noexcept;
    StrVec& operator=(StrVec &&) noexcept;
    ~StrVec();

    void push_back(const string &);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    string *begin() const {return elements;}
    string *end() const {return first_free;}

    std::string &operator[](size_t idx) {
        return *(elements + idx);
    }

    const std::string &operator[](size_t idx) const{
        return *(elements + idx);
    }

private:
    allocator<string> alloc;

    void check_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    pair<string*, string*> alloc_n_copy(const string*, const string*);

    void free();
    void reallocate();
    string *elements;
    string *first_free;
    string *cap;
};

bool operator==(const StrVec &v1, const StrVec v2);
bool operator!=(const StrVec &v1, const StrVec v2);
#endif