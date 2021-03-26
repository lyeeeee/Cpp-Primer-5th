#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#include <functional>
using namespace std;

int add(int i, int j) { return i + j;}

auto mod = [](int i, int j) { return i % j; };

class Div {
    public:

    int operator()(int i, int j) const { return i / j;}
};

map<string, function<int(int,int)>> calc = {
    {"+", add},
    {"-", std::minus<int>()},
    {"*", [](int i, int j){return i * j;}},
    {"/", Div()},
    {"%", mod}
};

int main(int argc, char* argv[]) {
    while (std::cout << "Pls enter as: num operator num :\n", true) {
		int lhs, rhs; std::string op;
		std::cin >> lhs >> op >> rhs;
		std::cout << calc[op](lhs, rhs) << std::endl;
	}

	return 0;
}