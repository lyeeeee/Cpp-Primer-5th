//
// Created by liyi on 2020/3/26.
//

#include <iostream>
#include <string>
#include "p7_27.h"
using namespace std;

int main() {
    Screen myScreen(5, 5, 'X');
    myScreen.move(4, 0).set('#').display(cout);
    cout << "\n";
    myScreen.display(cout);
    cout << "\n";
}
