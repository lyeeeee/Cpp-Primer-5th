#ifndef _P18_9SALES_DATA_EXCEPTION_H_
#define _P18_9SALES_DATA_EXCEPTION_H_
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>


class isbn_mismatch : public std::logic_error {
public:
    explicit isbn_mismatch(const std::string &s) : std::logic_error(s){}
    isbn_mismatch(const std::string &s, const std::string &lhs, const std::string &rhs): std::logic_error(s), left(lhs), right(rhs) {}

    const std::string left, right;
};

#endif