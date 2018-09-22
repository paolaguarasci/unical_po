
#ifndef MatriceOrdinaria_H
#define MatriceOrdinaria_H

#include "Punto.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene una lista di punti rappresentanti una matrice quadrata 20x20.
Ogni punto e` caratterizzato dalle seguenti informazioni:

    - i: una coordinata indicativa della riga (int);

    - j: una coordinata indicativa della colonna (int);

    - valore: il valore alla posizione (i,j) (int). Si assuma che il valore sia sempre >= 0;

Per i punti mancanti si assuma il valore 0.
Implementare nel file MatriceOrdinaria.cpp i metodi della classe MatriceOrdinaria.
    
*/
class MatriceOrdinaria   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Punto> punti;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Punto p) {punti.push_back(p); return true;}
    
    
    inline list<Punto>& getContent() { return punti; }
};
#endif
