#if !defined(GESTORECOMPUTERS_H)
#define GESTORECOMPUTERS_H
#include <algorithm>
#include <list>
#include <string>
#include "Computer.h"

class GestoreComputers : public std::list<Computer> {
 public:
  int countConnessi() {
    list<Computer> connessi;
    if (empty()) return -1;
    for (auto a = begin(); a != end(); a++) {
      if (a->getConnessoA() != "") connessi.push_back(*a);
    }
    return connessi.size();
  }
};

#endif  // GESTORECOMPUTERS_H
