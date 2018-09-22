
#ifndef Punto_H_
#define Punto_H_

#include <iostream>
#include <string>

using namespace std;


#include <algorithm>
#include <set>
#include <climits>
    

class Punto
{
private:
    int i;
    int j;
    int valore;
    
public:
    Punto(int _i = 0, int _j = 0, int _valore = 0) : i(_i), j(_j), valore(_valore) {}

    int getI() const { return i; }
    void setI(int v) { i = v; }

    int getJ() const { return j; }
    void setJ(int v) { j = v; }

    int getValore() const { return valore; }
    void setValore(int v) { valore = v; }

    

    bool operator==(const Punto& right) const { return i == right.i && j == right.j && valore == right.valore; }

friend ostream& operator<<(ostream& out, const Punto& x) { return out << "[" << x.i << ", " << x.j << ", " << x.valore << "]"; }
};

#endif
