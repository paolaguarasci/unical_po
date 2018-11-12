#include <iostream>
using namespace std;

int main() {
  unsigned s[20], *p = s + 20, i = 0;
  while (p != s) {
    p--;
    *p = ++i;
  }
  for (unsigned i = 0; i < 20; i++)
    cout << s[i] << endl;  // 20 ... 1 - in colonna

  return 0;
}
