#include "./p14_16String.h"
#include <string>
#include <memory>
#include <algorithm>
#include <iostream>


 String::String(const char *s) {
    char *p = const_cast<char*>(s);
    while (*p) {
        ++p;
    }
    range_initialize(s, ++p);
    // std::cout << (void*)end << " " << (void*)elements << std::endl;
    // std::cout << "c str init" << std::endl;
 }
 String::String(const String &s) {
    std::cout << "copy init beg" << std::endl;
    range_initialize(s.elements, s.end);
    // std::cout << "copy init end" << std::endl;
}
String&  String::operator=(const String &s) {
    auto newdata = alloc_n_copy(s.elements, s.end);
    free();
    elements = newdata.first;
    end = newdata.second;
    std::cout << "== init" << std::endl;
    return *this;
}

bool operator==(const String &lhs, const String &rhs) {
    if (lhs.length() != rhs.length()) { return false; }
    char *p1 = const_cast<char*>(lhs.c_str());
    char *p2 = const_cast<char*>(rhs.c_str());
    while (*p1) {
        if (*p1 != *p2) { return false; }
        p1++; p2++;
    }
    return true;
}

bool operator!=(const String &lhs, const String &rhs) {
    return !(lhs == rhs);
}

String::String(String &&s) noexcept{
    elements = s.elements;
    end = s.end;
    s.elements = s.end = nullptr;
    std::cout << "move copy" << std::endl;
}
String& String::operator=(String &&s) noexcept{
    if (&s != this) {
        free();
        elements = s.elements;
        end = s.end;
        s.elements = s.end = nullptr;
    }
    std::cout << "move ==" << std::endl;
    return *this;
}


 String::~String() {
     free();
}
pair<char*, char*>  String::alloc_n_copy(const char*first, const char*last) {
    // std::cout << "alloc_n_copy beg" << std::endl;
    // std::cout << end - beg << std::endl;
    auto data = alloc.allocate(last - first);
    // std::cout << "alloc_n_copy end" << std::endl;
    return {data, std::uninitialized_copy(first, last, data)};
}
void  String::range_initialize(const char*first, const char*last) {

    // std::cout << "range_initialize beg" << std::endl;
    auto data = alloc_n_copy(first, last);
    elements = data.first;
    end = data.second;
    // std::cout << "range_initialize end" << std::endl;
}
void  String::free() {
    if (elements) {
        //std::for_each(elements, end, [this](char &c) { alloc.destroy(&c); });
        for (char *pp = end; pp != elements;) {
            alloc.destroy(pp);
            pp--;
        }
        alloc.deallocate(elements, end - elements);
    }
}

int main() {
    String s1("hello");
    String s2("world");
    if (s1 == s2) {
        std::cout << "==" << std::endl;
    } else {
        std::cout << "!=" << std::endl;
    }
    std::cout << s1[2] << std::endl;
}

