#include "p16_16Vec.h"
#include <memory>
#include <algorithm>
// 更倾向于lambda写法
template <typename T>
void Vec<T>::push_back(const T &s) {
    check_n_alloc();
    alloc.construct(first_free++, s);
}

template <typename T>
pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
void Vec<T>::free() {
    if (elements) {
        auto p = elements;
        while (p != first_free) {
            alloc.destroy(p);
            p++;
        }
        alloc.deallocate(elements, cap - elements);
    }
}

template <typename T>
Vec<T>::Vec(const Vec<T> &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    elements = data.first;
    first_free = cap = data.second;
}

template <typename T>
Vec<T>::~Vec() {
    free();
}

template <typename T>
Vec<T> & Vec<T>::operator=(const Vec &s) {
    auto data = alloc_n_copy(s.begin(), s.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>::Vec(Vec<T> &&s) noexcept {
    elements = s.elements;
    first_free = s.first_free;
    cap = s.cap;
    s.elements = s.first_free = s.cap = nullptr;
}

template <typename T>
Vec<T>& Vec<T>::operator=(Vec &&s) noexcept {
    if (&s != this) {
        free();
        elements = s.elements;
        first_free = s.first_free;
        cap = s.cap;
        s.elements = s.first_free = s.cap = nullptr;
    }
    return *this;
}

template <typename T>
void Vec<T>::reallocate() {
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
int main() {
    Vec<string> v1, v2;
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