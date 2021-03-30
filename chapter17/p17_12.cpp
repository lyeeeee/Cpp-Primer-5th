#include <iostream>
#include <bitset>
#include <cassert>
#include "p17_11bitsetsolution.h"


using std::size_t;
using std::bitset;

template <std::size_t N>
Solution<N> &update_solution(Solution<N> &s, std::size_t idx, bool right) {
    if (idx > N) {
    } else {
        s.set(idx, right);
    }
    return s;
}
int main() {
    Solution<32u> s(0);
    update_solution(s, 1u, true);
    std::cout << s << std::endl;
}
