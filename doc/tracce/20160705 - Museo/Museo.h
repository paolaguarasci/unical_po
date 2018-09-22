
#ifndef Museo_H
#define Museo_H

#include "Opera.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

Questa classe contiene una lista di opere d'arte. Ogni opera e` caratterizzata dalle seguenti informazioni:

    - titolo: il titolo dell'opera (string);

    - artista: il nome dell'artista autore dell'opera (string);

    - x: una coordinata indicativa della posizione dell'opera (int);

    - y: una coordinata indicativa della posizione dell'opera (int);

    - tipo: il tipo dell'opera (un enumerativo con 3 possibili valori: QUADRO, STATUA, EDIFICIO);

    Implementare nel file Museo.cpp i metodi della classe Museo.
    
*/
class Museo   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Opera> opere;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    string metodo4();

    
    
    inline bool aggiungi(Opera o) {opere.push_back(o); return true;}
    
    
    inline list<Opera>& getContent() { return opere; }
};
#endif
