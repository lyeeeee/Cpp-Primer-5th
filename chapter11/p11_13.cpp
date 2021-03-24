#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>
#include <vector>
#include <algorithm>
#include "../include/Sales_item.h"

using namespace std;

int main() {
    string key;
    int val;
    vector<pair<string,int>> v;
    while (cin >> key >> val) {
        //pair<string, int> p(key, val);
        //pair<string, int> p = {key, val};
        pair<string, int> p = make_pair(key, val);
        v.push_back(p);
    }
    for_each(v.begin(), v.end(), [](const pair<string, int> &p) {cout << p.first << " " << p.second << endl;});
}