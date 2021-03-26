#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <functional>
using namespace std;

int main(int argc, char* argv[]) {
    vector<int> vec;
    count_if(vec.begin(), vec.end(), std::bind(greater<int>(), std::placeholders::_1, 1024));
    find_if(vec.begin(), vec.end(), std::bind(not_equal_to<string>(), std::placeholders::_1, "pooh"));
    std::transform(vec.begin(), vec.end(), vec.begin(), std::bind(std::multiplies<int>(), std::placeholders::_1, 2));
}