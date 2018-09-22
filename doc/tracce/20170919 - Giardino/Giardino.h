
#ifndef Giardino_H
#define Giardino_H

#include "Pianta.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene un archivio musicale di libri. Ogni album e` caratterizzato dalle seguenti informazioni:

    - genere: il genere della pianta (string, es: Aloe, Begonia, Ficus, Gardenia, Hedera, Mimosa, Rosa);

    - tipo: il tipo di pianta (un enumerativo con 3 possibili valori: CESPUGLIO, ARBUSTO, RAMPICANTE);

    - temperaturaMinima: temperatura minima tollerata dalla pianta (int);

    - prezzo: il prezzo della pianta (int >=0);
    
    Implementare nel file Giardino.cpp i metodi della classe Giardino.
    
*/
class Giardino   // questa riga e` corretta NON MODIFICARE
{
private:
    vector<Pianta> piante;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Pianta p) {piante.push_back(p); return true;}
    
    
    inline vector<Pianta>& getContent() { return piante; }
};
#endif
