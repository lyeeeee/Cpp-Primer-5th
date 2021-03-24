#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include <cstring>

using std::string;
using std::vector;
using std::cout;
using std::endl;

class Foo {
public:
    Foo sorted() &&;
    Foo sorted() const &;

private:
    vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    cout << "&& sorted" << endl;
    return *this;
}

Foo Foo::sorted() const & {
    cout << "const & sorted" << endl;
    return Foo(*this).sorted();
}

int main()
{
	Foo().sorted(); // call "&&"
	Foo f;
	f.sorted(); // call "const &"
}