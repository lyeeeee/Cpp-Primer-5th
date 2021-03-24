#include <iostream>
#include <bitset>
#include <cassert>


using std::size_t;
using std::bitset;

template <size_t N>
class Solution {
public:

    Solution() = default;
    Solution(const std::string &s): bits(s){};

    void answer(size_t n, bool b) {
        bits.set(n-1, b);
    }

    size_t score() const {
        return bits.count();
    }
private:
    bitset<N> bits;
};
