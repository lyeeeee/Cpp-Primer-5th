//
// Created by liyi on 2020/3/25.
//

// 第一个合法，第二个合法，第三个不合法，第四个合法
#include <iostream>
int main() {
    // std::cout << "/*";
    // std::cout << "*/";
    // std::cout << /* "*/" */;
    // std::cout << /* "*/" /* "/*" */;

    std::cout << "/*";
    std::cout << "*/";
    std::cout << /* "*/" */";
    std::cout << /* "*/" /* "/*" */;
}
