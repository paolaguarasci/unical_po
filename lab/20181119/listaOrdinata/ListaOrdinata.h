#if !defined(LISTAORDINATA_H)
#define LISTAORDINATA_H

#include <algorithm>
#include <iostream>
#include <list>
#include <string>

using namespace std;

class ListaOrdinata : protected list<string> {
 public:
  void push(const string& stringa) {
    list<string>::iterator it = list<string>::begin();
    while (it != list<string>::end() && stringa > (*it)) {
      it++;
    }
    insert(it, stringa);
  }

  void stampa() {
    for (list<string>::iterator it = begin(); it != end(); it++) {
      cout << (*it) << endl;
    }
  }
  int size() { return list<string>::size(); }
};

#endif  // LISTAORDINATA_H
