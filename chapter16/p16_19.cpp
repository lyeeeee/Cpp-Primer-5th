#include <memory>
#include <iostream>
#include "../chapter7/p7_41.h"
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


template<typename T>
void print_container(T &c) {
  for (typename T::size_type i = 0; i < c.size(); ++i) {
    cout << c[i] << endl;
  }
}

int main() {
  vector<string> v = {"1", "2", "3"};
  print_container(v);
}