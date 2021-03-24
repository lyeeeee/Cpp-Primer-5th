#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;



int main() {
    unique_ptr<int> p(new int(4));
    unique_ptr<int> q = p;
}