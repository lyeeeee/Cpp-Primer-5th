#include <iostream>

using namespace std;

class number{

public:
    number() {
        num = unique++;
    }

    number(const number & n) {
        num = unique++;
    }
    int num;
    static int unique;
};

int number::unique = 0;


void f(const number &s) {
    cout << s.num << endl;
}
int main() {
    number a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}