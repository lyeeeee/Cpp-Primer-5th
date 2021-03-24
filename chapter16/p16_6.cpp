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

template <typename T, unsigned N> constexpr
unsigned size(const T (&arr)[N]) {
    return N;
}