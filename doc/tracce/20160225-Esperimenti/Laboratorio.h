
#ifndef Laboratorio_H
#define Laboratorio_H

#include "Esperimento.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di esperimenti. Ogni esperimento e` caratterizzato dalle seguenti informazioni:

    - titolo: il titolo dell'esperimento (string);

    - scienziato: lo scienziato che ha condotto l'esperimento (string);

    - tempo1: la durata della prima fase dell'esperimento (int);

    - tempo2: la durata della seconda fase dell'esperimento (int);

    - tempo3: la durata della terza fase dell'esperimento (int);

    - costo: il costo dell'esperimento (int);

    Implementare nel file Laboratorio.cpp i metodi della classe Laboratorio.
    
*/
class Laboratorio   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Esperimento> esperimenti;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Esperimento e) {esperimenti.push_back(e); return true;}
    
    
    inline list<Esperimento>& getContent() { return esperimenti; }
};
#endif
