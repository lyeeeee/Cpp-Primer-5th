#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;



int main() {
    // 正确， 调用函数会创建一个临时的共享指针，此时的引用计数为2，在离开调用函数作用域后，引用计数恢复为1
}