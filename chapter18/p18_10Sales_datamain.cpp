#include <iostream>
#include <vector>
#include "p18_9Sales_data_exception.h"
#include "p18_9Sales_data.h"

int main() {
    Sales_data data;
    data = string("hello world", 2, 20);
    Sales_data data2("hwllo", 1, 10);
    try {
        data += data2;
    } catch (isbn_mismatch &im) {
        cout << "isbn mismatch" << endl;
    }
    std::cout << data << std::endl;
    // 不捕获异常程序会执行terminate调用
}