#include "./p14_16StrVec.h"
#include <memory>
#include <algorithm>
// 更倾向于lambda写法
void StrVec::push_back(const string &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        auto p = elements;
        while (p != first_free) {
            alloc.destroy(p);
            p++;
        }
        alloc.deallocate(elements, cap - elements);
    }
}

StrVec::StrVec(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}

StrVec::~StrVec() {
    free();
}

StrVec & StrVec::operator=(const StrVec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

StrVec::StrVec(StrVec &&s) noexcept {
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec &&s) noexcept {
    if (&s != this) {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() :1;
    auto newdata = alloc.allocate(newcapacity);
    auto dest = newdata;
    auto src = elements;
    for (size_t i = 0; i != size(); ++i) {
        alloc.construct(dest++, std::move(*src++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

bool operator==(const StrVec &v1, const StrVec v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    string *p = v1.begin();
    string *q = v2.begin();
    while (p != v1.end()) {
        if (*p != *q) {return false;}
        p++; q++;
    }
    return true;
}

bool operator!=(const StrVec &v1, const StrVec v2) {
    return !(v1 == v2);
}

int main() {
    StrVec v1, v2;
    v1.push_back(string("hello"));
    v1.push_back(string("hello"));

    v2.push_back(string("world"));
    v2.push_back(string("world"));

    if (v1 == v2) {
        std::cout << "==" << std::endl;
    } else {
        std::cout << "!=" << std::endl;
    }

    std::cout << v1[0] << std::endl;
}