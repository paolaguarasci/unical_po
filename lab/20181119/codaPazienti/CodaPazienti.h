#
#if !defined(CODAPAZIENTI_H)
#define CODAPAZIENTI_H

#include <iostream>
#include <list>
#include <string>
#include "Paziente.h"

class CodaPazienti : protected list<Paziente> {
 public:
  void push(const Paziente& p) {
    list<Paziente>::iterator it = list<Paziente>::begin();
    while (it != list<Paziente>::end() && it->getCodice() >= p.getCodice())
      it++;
    list<Paziente>::insert(it, p);
  }
  void stampa() {
    for (list<Paziente>::iterator it = list<Paziente>::begin();
         it != list<Paziente>::end(); it++) {
      cout << it->getCodice() << " " << it->getNome() << endl;
    }
  }
  size_t size() { return list<Paziente>::size(); }

 private:
};

#endif  // CODAPAZIENTI_H
