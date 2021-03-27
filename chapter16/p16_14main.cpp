#include <memory>
#include <iostream>
#include "p16_14Screen.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


int main() {
    Screen<2,3> screen('a');
    cout << screen << endl;
    std::cin >> screen;
    cout << screen << endl;
}