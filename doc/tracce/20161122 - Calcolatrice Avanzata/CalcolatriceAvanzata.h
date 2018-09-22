
#ifndef CalcolatriceAvanzata_H
#define CalcolatriceAvanzata_H

#include "QuadruplaNumeri.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di quadruple di numeri. Ogni quadrupla e` caratterizzata dalle seguenti informazioni:

    - num1: il primo numero della quadrupla (int);

    - num2: il secondo numero della quadrupla (int);

    - num3: il terzo numero della quadrupla (int);
    
    - num3: il quarto numero della quadrupla (int).
    
    Implementare nel file CalcolatriceAvanzata.cpp i metodi della classe CalcolatriceAvanzata.
    
*/
class CalcolatriceAvanzata   // questa riga e` corretta NON MODIFICARE
{
private:
    list<QuadruplaNumeri> numeri;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(QuadruplaNumeri c) {numeri.push_back(c); return true;}
    
    
    inline list<QuadruplaNumeri>& getContent() { return numeri; }
};
#endif
