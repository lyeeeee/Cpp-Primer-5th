//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

int main() {
    int cnt = 1;
    string word;
    string pre;
    int max = 1;
    string maxWord;
    while (cin >> word) {
        if (word == pre) {
            cnt++;
            if (cnt > max) {
                maxWord = word;
                max = cnt;
            }
        } else {
            cnt = 1;
            pre = word;
        }
    }
    cout << maxWord << " " << max << endl;
}
