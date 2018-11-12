#include <iostream>
#include <string>
#include "Stack.h"
bool checkParentesi(std::string esp) {
  Stack<int> pila;
  std::string::iterator i = esp.begin();
  for (; i != esp.end(); i++) {
    if ((*i) == '(') pila.push(1);
    if ((*i) == ')' && pila.stackVuoto())
      return false;
    else if ((*i) == ')' && !pila.stackVuoto())
      pila.pop();
  }
  return pila.stackVuoto();
}
int main() {
  string esp;
  std::getline(std::cin, esp);
  if (checkParentesi(esp))
    cout << "Ben parentesizzata!";
  else
    cout << "NON ben parentesizzata!";
  return 0;
}