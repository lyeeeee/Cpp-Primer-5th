#include <iostream>
#include <sstream>
using namespace std;

istream& func(istream& in) {
    char c;
    while (in >> c) {
        cout << c;
    }
    cout << endl;
    in.clear();
    return in;
}

int main() {
    istringstream ins("hello world");
    func(ins);
}