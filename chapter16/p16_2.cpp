#include <memory>
#include <iostream>

using std::string;

template<typename T>
int compare(const T& a, const T&b) { return a < b;}