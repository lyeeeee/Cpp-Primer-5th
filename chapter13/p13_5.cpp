#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0){}
    HasPtr(const HasPtr & obj) : ps(new string(*ps)), i(obj.i){}
private:
    string *ps;
    int i;
};