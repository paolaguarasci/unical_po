
#ifndef Amazon_H
#define Amazon_H

#include "Articolo.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di articoli. Ogni articolo e' caratterizzato dalle seguenti informazioni:

    - nome: il nome dell'articolo (string);

    - venditore: il nome del venditore dell'articolo (string);

    - prezzo: il prezzo dell'articolo (int);

    - recensione: la recensione media dell'articolo fornita dagli utenti (NESSUNA, UNA_STELLA, DUE_STELLE, TRE_STELLE, QUATTRO_STELLE, CINQUE_STELLE);

    - spedizione: la modalita' di spedizione per l'articolo (AMAZON_PRIME, AMAZON_STANDARD, ALTRO);
    
    Implementare nel file Amazon.cpp i metodi della classe Amazon.
    
*/
class Amazon   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Articolo> articoli;

public:
    // DESCRIZIONE NEL FILE .cpp
    string metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Articolo s) {articoli.push_back(s); return true;}
    
    
    inline list<Articolo>& getContent() { return articoli; }
};
#endif
