#include <iostream>
#include <map>
#include <set>
#include <string>
#include <list>

using namespace std;

int main() {
    //可以定义 vector<int>::iterator 到 int 的map，但是不能定义 list<int>::iterator 到 int 的map。因为map的键必须实现 < 操作，list 的迭代器不支持比较运算。
}