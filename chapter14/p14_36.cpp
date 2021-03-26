#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Func {
public:
    string operator()(istream &in) {
        string str;
        getline(in, str);
        return in ? str : std::string();
    }

};
int main(int argc, char* argv[]) {
    Func f;
    vector<string> vec;
    for (string s; !(s = f(cin)).empty();) {
        vec.push_back(s);
    }
    for_each(vec.begin(), vec.end(), [](const string &s){cout << s << endl;});
}