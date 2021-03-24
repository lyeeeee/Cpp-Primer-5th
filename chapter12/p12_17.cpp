#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

using namespace std;



int main() {
    /*
(a) 不合法。在定义一个 unique_ptr 时，需要将其绑定到一个new 返回的指针上。
(b) 不合法。试图释放栈空间的对象
(c) 合法。但是也可能会使得 pi2 成为空悬指针。
(d) 不合法。当 p3 被销毁时，它试图释放一个栈空间的对象。
(e) 合法。
(f) 不合法。p5 和 p2 指向同一个对象，当 p5 和 p2 被销毁时，会使得同一个指针被释放两次。
    */
}