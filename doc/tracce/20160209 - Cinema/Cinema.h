
#ifndef Cinema_H
#define Cinema_H

#include "Film.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di film. Ogni film e` caratterizzato dalle seguenti informazioni:

    - titolo: il titolo del film (string);

    - anno: l'anno in cui il film e' stato girato (int);

    - incasso: l'incasso ottenuto dal film (int);

    - regista: il regista del film (string);

    - genere: il genere del film (NONDEFINITO, ANIMAZIONE, COMICO, COMMEDIA, DRAMMATICO, FANTASY, HORROR, STORICO).
    
    Implementare nel file Cinema.cpp i metodi della classe Cinema.
    
*/
class Cinema   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Film> film;

public:
    // DESCRIZIONE NEL FILE .cpp
    Genere metodo1();

    // DESCRIZIONE NEL FILE .cpp
    string metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Film f) {film.push_back(f); return true;}
    
    
    inline list<Film>& getContent() { return film; }
};
#endif
