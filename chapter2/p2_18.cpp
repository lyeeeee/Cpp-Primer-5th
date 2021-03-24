
#include <iostream>

using namespace std;

int main() {
    int i = 10;
    int* p = nullptr;
    p = &i;
    *p = 1;
    cout << *p << " " << i << endl;
}
