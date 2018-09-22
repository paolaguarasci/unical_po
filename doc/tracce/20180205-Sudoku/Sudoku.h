
#ifndef Sudoku_H
#define Sudoku_H

#include "Cella.h"

#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*

	Questa classe contiene una lista di celle. Ogni cella e` caratterizzata dalle seguenti informazioni:

    - riga: la riga della cella (int, varia tra 1 e 9);

    - colonna: la colonna della cella (int, varia tra 1 e 9);

    - simbolo: il simbolo della cella (int, varia tra 1 e 9);

    Implementare nel file Sudoku.cpp i metodi della classe Sudoku.
    
    NB: E' possibile che nella lista siano presenti piu'
	celle uguali (stessa riga, stessa colonna, stesso simbolo).
    
*/
class Sudoku   // questa riga e` corretta NON MODIFICARE
{
private:
    list<Cella> sudoku;

public:
    // DESCRIZIONE NEL FILE .cpp
    int metodo1();

    // DESCRIZIONE NEL FILE .cpp
    int metodo2();

    // DESCRIZIONE NEL FILE .cpp
    int metodo3();

    // DESCRIZIONE NEL FILE .cpp
    int metodo4();

    
    
    inline bool aggiungi(Cella c) {sudoku.push_back(c); return true;}
    
    
    inline list<Cella>& getContent() { return sudoku; }
};
#endif
