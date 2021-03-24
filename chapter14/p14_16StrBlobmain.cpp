#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <memory>
#include "p14_16StrBlob.h"




int main() {
    StrBlob blob = {"hello", "world"};
    StrBlobPtr p1 = blob.begin();
    StrBlobPtr p2 = blob.end();
    StrBlobPtr p = blob.begin();
    if (p1 != p2) {
        std::cout << "p1 != p2" << std::endl;
    }

    if (p1 == p) {
        std::cout << "p1 == p3" << std::endl;
    }
    std::cout << blob[1] << std::endl;
}