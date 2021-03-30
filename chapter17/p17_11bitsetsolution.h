#ifndef _P17_11_H_
#define _P17_11_H_
#include <iostream>
#include <bitset>
#include <cassert>


using std::size_t;
using std::bitset;

template <std::size_t N>
class Solution {
public:
    friend std::ostream & operator<<(std::ostream &os, const Solution<N> &s) {
        os << s.solu;
        return os;
    }
    Solution(std::size_t s): solu{s}{
        std::cout <<"1"<<std::endl;
    }

    Solution(const std::string &s):solu{s}{}

    void set(std::size_t idx, bool right) {
        solu.set(idx, right);
    }

private:
    bitset<N> solu;
};
#endif
