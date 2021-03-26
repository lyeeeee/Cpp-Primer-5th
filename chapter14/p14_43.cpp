#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <functional>
using namespace std;


int main(int argc, char* argv[]) {
    vector<int> ivec = {1,2,3,4,5,6,7};
    std::modulus<int> m;
    int in;
    std::cin >> in;
    auto ava = std::any_of(ivec.cbegin(), ivec.cend(), [&in, &m](int i){return 0 == m(in, i);});
    if (ava) {
        cout << "ava" << endl;
    }
}