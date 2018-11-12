//  g++ esercizio.cpp -std=c++17
#include <iostream>
#include <string>
using namespace std;

template <typename T1, typename T2>
class Pair {
  T1 first;
  T2 second;

 public:
  Pair() {}  // construttore senza parametri che non fa niente
  Pair(T1 x, T2 y) : first{x}, second{y} {}
  T1 getFirst() { return first; }
  T2 getSecond() { return second; }
  void setFirst(const T1 &x) { first = x; }
  void setSecond(const T2 &x) { second = x; }
};

int main() {
  Pair<string, int> students[10];
  string m;
  int v;

  for (int i = 0; i < 10; i++) {
    cin >> m >> v;
    students[i].setFirst(m);
    students[i].setSecond(v);
  }

  int indexMaxGrade = 0;
  for (int i = 1; i < 10; i++) {
    if (students[i].getSecond() > students[indexMaxGrade].getSecond())
      indexMaxGrade = i;
  }

  cout << students[indexMaxGrade].getFirst();
  return 0;
}