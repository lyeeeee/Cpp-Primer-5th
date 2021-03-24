#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


template <typename T>
void print_container(T &c) {
  for (T::size_type i = 0; i < c.size(); ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}