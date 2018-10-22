#ifndef STACK_H_
#define STACK_H_
#include <vector>
using namespace std;
template <class T>
class Stack
{
private:
  vector<T> s;

public:
  Stack() {}
  void push(const T &e) { s.push_back(e); }
  bool pop()
  {
    if (s.empty())
      return false;
    s.pop_back();
    return true;
  }
  T top() { return s.back(); }
  bool stackVuoto() { return s.empty(); }
  void svuota() { s.clear(); }
};
#endif