#if !defined(CODACONGENTLEMAN_H)
#define CODACONGENTLEMAN_H

#include <list>
#include "Persona.h"

class CodaConGentleman : protected list<Persona> {
 public:
  const Persona& pop() {
    list<Persona>::iterator it = list<Persona>::begin();
    Persona primo = list<Persona>::front();
    if (primo.getSesso() == M) {
      cout << "Il primo è un uomo";
      it++;  // altrimenti trova il primo come prossimo uomo!
      while (it != list<Persona>::end() && it->getSesso() != M) {
        it++;
      }
      list<Persona>::insert(it, primo);
    }
    list<Persona>::pop_front();
    return primo;
  }

  void push_back(const Persona& p) { list<Persona>::push_back(p); }
  size_t size() { return list<Persona>::size(); }

  void stampa() {
    for (list<Persona>::iterator it = list<Persona>::begin();
         it != list<Persona>::end(); it++) {
      cout << it->getSesso() << " " << it->getNome() << endl;
    }
  }
};
#endif  // CODACONGENTLEMAN_H