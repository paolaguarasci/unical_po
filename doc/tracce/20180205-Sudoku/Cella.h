
#ifndef Cella_H_
#define Cella_H_

#include <iostream>
#include <string>

using namespace std;


#include <climits>
    

class Cella
{
private:
    int riga;
    int colonna;
    int simbolo;
    
public:
    Cella(int _riga = 1, int _colonna = 1, int _simbolo = 1) : riga(_riga), colonna(_colonna), simbolo(_simbolo) {}

    int getRiga() const { return riga; }
    void setRiga(int v) { riga = v; }

    int getColonna() const { return colonna; }
    void setColonna(int v) { colonna = v; }

    int getSimbolo() const { return simbolo; }
    void setSimbolo(int v) { simbolo = v; }

    

    bool operator==(const Cella& right) const { return riga == right.riga && colonna == right.colonna && simbolo == right.simbolo; }

friend ostream& operator<<(ostream& out, const Cella& x) { return out << "[" << x.riga << ", " << x.colonna << ", " << x.simbolo << "]"; }
};

#endif
