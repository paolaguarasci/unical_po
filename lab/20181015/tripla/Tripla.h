#ifndef TRIPLA_H
#define TRIPLA_H
#include <iostream>
template <typename T1, typename T2, typename T3>
class Tripla
{
private:
  T1 one;
  T2 two;
  T3 three;

public:
  Tripla() : one(), two(), three() {}
  Tripla(const T1 &a, const T2 &b, const T3 &c) : one(a), two(b), three(c) {}

  const T1 &getOne() const { return one; }
  const T2 &getTwo() const { return two; }
  const T3 &getThree() const { return three; }
  void setOne(const T1 &one) { this->one = one; }
  void setTwo(const T2 &two) { this->two = two; }
  void setThree(const T3 &three) { this->three = three; }
bool operator==(const Tripla& rhs) {
  return (one == rhs.one) && (two == rhs.two) && (three == rhs.three);
}
  void stampa() const
  {
    std::cout << "<" << one << ", " << two << ", " << three << ">";
  }
  void leggi()
  {
    std::cin >> one >> two >> three;
  }
};

#endif // TRIPLA_H