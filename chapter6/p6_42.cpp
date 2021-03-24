//
// Created by liyi on 2020/3/26.
//
#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

string make_plural(size_t ctr, const string &word, const string &ending = "s") {
    return ctr > 1 ? word + ending : word;
}


