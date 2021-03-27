#ifndef __P16_16_H__
#define __P16_16_H__
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

template <typename T>
class Vec {
public:
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr){}
    Vec(std::initializer_list<T> li): elements(nullptr), first_free(nullptr), cap(nullptr){
        auto data = alloc_n_copy(li.begin(), li.end());
        elements = data.first;
        first_free = cap = data.second;
    }
    Vec(const Vec<T> &s);
    Vec<T>& operator=(const Vec<T> &);

    Vec(Vec<T> &&s) noexcept;
    Vec<T>& operator=(Vec<T> &&) noexcept;
    ~Vec();

    void push_back(const T &);
    size_t size() const {return first_free - elements;}
    size_t capacity() const {return cap - elements;}

    T *begin() const {return elements;}
    T *end() const {return first_free;}

    T &operator[](size_t idx) {
        return *(elements + idx);
    }

    const T &operator[](size_t idx) const{
        return *(elements + idx);
    }

    friend bool operator==(const Vec<T> &v1, const Vec<T> &v2) {
        if (v1.size() != v2.size()) {
            return false;
        }

        T *p = v1.begin();
        T *q = v2.begin();
        while (p != v1.end()) {
            if (*p != *q) {return false;}
            p++; q++;
        }
        return true;
    }
    friend bool operator!=(const Vec<T> &v1, const Vec<T> &v2) {
        return !(v1 == v2);
    }

private:
    allocator<T> alloc;

    void check_n_alloc() {
        if (size() == capacity()) {
            reallocate();
        }
    }

    pair<T*, T*> alloc_n_copy(const T*, const T*);

    void free();
    void reallocate();
    T *elements;
    T *first_free;
    T *cap;
};


#endif