#if !defined(CODAMEDICODIFAMIGLIA_H)
#define CODAMEDICODIFAMIGLIA_H

#include <list>
#include "Persona.h"

class CodaMedicoDiFamiglia : protected list<Persona> {
 public:
  const Persona& pop() {
    list<Persona>::iterator it = list<Persona>::begin();
    while (it != list<Persona>::end() && it->getTipo() != INFORMATORE) {
      it++;
    }
    // it++;
    if (std::distance(list<Persona>::begin(), it) <= 10) {
      cout << "Distanza " << std::distance(list<Persona>::begin(), it) << endl;
      // Persona info = *it;
      list<Persona>::push_front(*it);
      list<Persona>::erase(it);
    }
    Persona first = list<Persona>::front();
    list<Persona>::pop_front();
    return first;
  }

  void push_back(const Persona& p) { list<Persona>::push_back(p); }
  size_t size() { return list<Persona>::size(); }

  void stampa() {
    for (list<Persona>::iterator it = list<Persona>::begin();
         it != list<Persona>::end(); it++) {
      cout << it->getTipo() << " " << it->getNome() << endl;
    }
  }
};
#endif  // CODAMEDICODIFAMIGLIA_H