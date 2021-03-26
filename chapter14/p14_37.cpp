#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Func {
public:
    Func(int e): elem(e){}
    bool operator()(int target) {
        return target == elem;
    }
private:
    int elem;
};
int main(int argc, char* argv[]) {
    vector<int> vec = {1,2,3,4,5,6,7};
    replace_if(vec.begin(), vec.end(), Func(4), 5);
    for_each(vec.begin(), vec.end(), [](int i){cout << i;});
}