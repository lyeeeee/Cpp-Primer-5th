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
  for (typename T::iterator i = c.begin(); i != c.end(); ++i) {
    cout << c[i] << " ";
  }
  cout << endl;
}