#include <iostream>
#include <vector>
#include "p18_9Sales_data_exception.h"
#include "p18_9Sales_data.h"

int main() {
    Sales_data data;
    data = string("hello world");
    Sales_data data2("hwllo", 1, 10);
    data += data2;
    std::cout << data << std::endl;
}