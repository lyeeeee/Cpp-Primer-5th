//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;


int func(int arg) {
    int i = 0;
    static size_t cnt = 0;
    return cnt++;
}
int main() {
    int i;
    cin >> i;
    func(i);
}
