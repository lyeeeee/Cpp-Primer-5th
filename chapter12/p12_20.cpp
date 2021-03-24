#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include "p12_19.h"

using namespace std;



int main() {
    StrBlob sb({"1","2","3"});
    StrBlobPtr p = sb.begin();
    while (p != sb.end()) {
        cout << p.dref() << endl;
        p.incr();
    }
}