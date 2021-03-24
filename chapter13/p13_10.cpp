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

//当一个 StrBlob 对象被销毁时，shared_ptr 的引用计数会减少。当 StrBlobPtr 对象被销毁时，不影响引用计数。