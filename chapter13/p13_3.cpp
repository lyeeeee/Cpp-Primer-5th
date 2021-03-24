#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>
#include <fstream>
#include <sstream>
#include "p12_27.h"
#include <cstring>

using namespace std;

// 拷贝 StrBlob时，会使 shared_ptr 的引用计数加1。当我们拷贝 StrBlobPtr 时，引用计数不会变化。