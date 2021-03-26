#include <memory>
#include <iostream>

using namespace std;
class Func {
public:
    int operator ()(bool i, int a, int b) {
        return i ? a : b;
    }
};
int main(int argc, char* argv[]) {
    Func f;
    cout << f(false, 1,2) << endl;
}