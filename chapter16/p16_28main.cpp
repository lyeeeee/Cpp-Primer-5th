#include "p16_28my_unique_ptr.h"
#include "p16_28my_shared_ptr.h"
#include <string.h>

int main() {
    my_unique_ptr<string> ptr;
    std::string *name = new std::string("hello");
    ptr.reset(name);
}