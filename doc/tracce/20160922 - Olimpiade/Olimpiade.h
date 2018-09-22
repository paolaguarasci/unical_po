
#ifndef Olimpiade_H
#define Olimpiade_H

#include "Atleta.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di atleti. Ogni atleta e` caratterizzato dalle seguenti informazioni:

    - atleta: il nome di un atleta (string);
    
    - nazione: la nazione di appartenza dell'atleta (string);

    - eta: l'eta' anagrafica dell'atleta (int);

    - numeroOri: numero di medaglie d'oro vinte,
    
    - numeroArgenti: numero di medaglie d'argento vinte,
    
    - numeroBronzi: numero di medaglie di bronzo vinte.
    
    Implementare nel file Olimpiade.cpp i metodi della classe Olimpiade.
    
*/
class Olimpiade   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Atleta> atleti;

public:
    // DESCRIZIONE NEL FILE .cpp
    string metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Atleta a) {atleti.push_back(a); return true;}
    
    
    inline list<Atleta>& getContent() { return atleti; }
};
#endif
