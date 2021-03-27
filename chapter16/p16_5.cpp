#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


template <typename Array>
void print(Array &arr) {
    for (auto i : arr) {
        cout << i << endl;
    }
}

int main() {
    int arr[] = {1,2,3, 4, 5, 6, 7};
    print(arr);
}