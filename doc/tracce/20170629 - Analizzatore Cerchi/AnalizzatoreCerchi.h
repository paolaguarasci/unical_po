
#ifndef AnalizzatoreCerchi_H
#define AnalizzatoreCerchi_H

#include "Cerchio.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di cerchi. Ogni cerchio e' caratterizzato dalle seguenti informazioni:

    - x: coordinata x del centro (int);

    - y: coordinata y del centro (int);

    - raggio: lunghezza del raggio (int);

    Implementare nel file AnalizzatoreCerchi.cpp i metodi della classe AnalizzatoreCerchi.
    
*/
class AnalizzatoreCerchi   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Cerchio> cerchi;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Cerchio s) {cerchi.push_back(s); return true;}
    
    
    inline list<Cerchio>& getContent() { return cerchi; }
};
#endif
