#ifndef __P16_21DEBUGDELETE_H__
#define __P16_21DEBUGDELETE_H__
#include <memory>
#include <iostream>
#include <vector>

using std::string;
using std::cout;
using std::endl;
using std::vector;


class DeleteDebug {
public:
  DeleteDebug(std::ostream &os = std::cerr):out(os){}

  template<typename T>
  void operator()(T *p) const{
    out << "deleteing unique_ptr" << std::endl;
    delete p;
  }
private:
  std::ostream &out;
};
#endif

// int main() {
//   DeleteDebug d(std::cout);
//   int *i = new int();
//   d(i);
// }
