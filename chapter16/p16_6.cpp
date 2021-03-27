#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


/**
 *
 *
*/

template <typename T, unsigned N>
T* beg(const T (&arr)[N]) {
    return arr;
}

template <typename T, unsigned N>
T* end(const T (&arr)[N]) {
    return arr + N;
}