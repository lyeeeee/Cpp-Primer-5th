#include <iostream>
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
    istream& in = func(cin);
    cout << in.good() << endl;
}