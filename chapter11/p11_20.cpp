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
    string word;
    map<string, int> cnt;
    while (cin >> word) {
        auto it = cnt.insert({word, 1});
        if (it.second == false) {
            cnt[word]++;
        }
    }
}