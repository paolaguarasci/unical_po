
#ifndef Mobilificio_H
#define Mobilificio_H

#include "Mobile.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di mobili. Ogni mobile e` caratterizzato
   dalle seguenti informazioni:
    - nomeMobile: il nome di un mobile (string);
    - produttore: il nome del produttore che ha prodotto il mobile (string);
    - prezzo: il prezzo del mobile (int);
    - tipo: il tipo del mobile (un enumerativo con 5 possibili valori: TAVOLO,
   SEDIA, COMODINO, ARMADIO;
    - collaboratore: il produttore che ha collaboratore nella realizzazione del
   mobile, stringa vuota se non esiste un collaboratore (string). Implementare
   nel file Mobilificio.cpp i metodi della classe Mobilificio.

*/
class Mobilificio  // questa riga e` corretta NON MODIFICARE
{
 private:
  list<Mobile> mobili;
  int mediaProd(string prod);
  int prezzoMaxProduttore(string prod);
  bool economico(string prod);
  int contaMobili(string prod);
  vector<string> getProduttori();
  void getCollaborazioni(list<string> &collaborazioni, const string &key);

 public:
  // DESCRIZIONE NEL FILE .cpp
  int metodo1();

  // DESCRIZIONE NEL FILE .cpp
  int metodo2();

  // DESCRIZIONE NEL FILE .cpp
  int metodo3();

  // DESCRIZIONE NEL FILE .cpp
  int metodo4();

  inline bool aggiungi(Mobile s) {
    mobili.push_back(s);
    return true;
  }

  inline list<Mobile> &getContent() { return mobili; }
};
#endif
