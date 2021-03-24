#include <memory>
#include <iostream>

using namespace std;
class Func {
public:
    int operator()(bool v1, int v2, int v3) {
        if (v1) return v2;
        else return v3;
    }

};
int main(int argc, char* argv[]) {
    Func f;
    cout << f(false, 1,2) << endl;
}