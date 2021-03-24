#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include <cstring>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()) : ps(new string(s)), i(0){}
    HasPtr(const HasPtr & obj) {
        ps = new string(*(obj.ps));
        i = obj.i;
    }

    HasPtr& operator=(const HasPtr &obj){
        string *new_ps = new string(*obj.ps);
        if (!ps) {
            delete ps;
        }
        ps = new_ps;
        i = obj.i;
        return *this;
    }
public:
    string *ps;
    int i;
};