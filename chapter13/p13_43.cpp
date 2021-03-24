#include "./p13_40.h"
#include <memory>
// 更倾向于lambda写法
void StrVec::push_back(const string &s) {
    check_n_alloc();
    StrVec::alloc.construct(first_free++, s);
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
    auto data = StrVec::alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free,[this](string *ele){alloc.destroy(ele);});
        StrVec::alloc.deallocate(elements, cap - elements);
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

void StrVec::reallocate() {
    auto newcapacity = size() ? 2*size() :1;
    auto newdata = StrVec::alloc.allocate(newcapacity);
    auto dest = newdata;
    auto src = elements;
    for (size_t i = 0; i != size(); ++i) {
        StrVec::alloc.construct(dest++, std::move(*src++));
    }
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}