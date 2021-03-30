#include <iostream>
#include <bitset>
#include <vector>

using namespace std;


int main() {
    vector<int> vec = {1,2,3,5,8,13,21};

    bitset<32> bs;
    for (auto i = vec.cbegin(); i != vec.cend(); ++i) {
        bs.set(*i);
    }
    std::cout << bs << std::endl;
}