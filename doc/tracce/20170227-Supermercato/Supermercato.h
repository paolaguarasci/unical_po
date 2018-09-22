
#ifndef Supermercato_H
#define Supermercato_H

#include "Prodotto.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di prodotti. Ogni prodotto e` caratterizzato dalle seguenti informazioni:

    - descrizione: una descrizione del prodotto (string);

    - categoria: la categoria di appartenenza del prodotto (ALTRO,MACELLERIA,ORTOFRUTTA,PESCHERIA,PROFUMERIA);

    - rivenditore: il rivenditore che vende il prodotto (string);

    - costo: il costo del prodotto (unsigned);

    Implementare nel file Supermercato.cpp i metodi della classe Supermercato.
    
*/
class Supermercato   // questa riga e` corretta NON MODIFICARE
{
private:
    vector<Prodotto> prodotti;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Prodotto f) {prodotti.push_back(f); return true;}
    
    
    inline vector<Prodotto>& getContent() { return prodotti; }
};
#endif
