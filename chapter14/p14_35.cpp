#include <memory>
#include <iostream>

using namespace std;
class Func {
public:
    string operator()(istream &in) {
        string str;
        in >> str;
        return in ? str : std::string();
    }

};
int main(int argc, char* argv[]) {
    Func f;
    cout << f(std::cin) << endl;
}