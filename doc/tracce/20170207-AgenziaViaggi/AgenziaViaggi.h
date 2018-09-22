
#ifndef AgenziaViaggi_H
#define AgenziaViaggi_H

#include "Viaggio.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

    Questa classe contiene una lista di viaggi. Ogni viaggio e` caratterizzato dalle seguenti informazioni:

    - destinazione: la citta' destinazione del viaggio (string);

    - continente: il continente in cui si trova la destinazione (AFRICA,AMERICA,ASIA,EUROPA,OCEANIA);

    - distanza: la distanza del viaggio in KM (unsigned);

    - costo: il costo del viggio a persona (unsigned);

    - prenotazioni: il numero di prenotazioni (unsigned);
    
    Implementare nel file AgenziaViaggi.cpp i metodi della classe AgenziaViaggi.
    
*/
class AgenziaViaggi   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Viaggio> viaggi;

public:
    // DESCRIZIONE NEL FILE .cpp
    string metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    string metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Viaggio f) {viaggi.push_back(f); return true;}
    
    
    inline list<Viaggio>& getContent() { return viaggi; }
};
#endif
