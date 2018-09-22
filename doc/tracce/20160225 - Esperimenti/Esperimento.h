
#ifndef Esperimento_H_
#define Esperimento_H_

#include <iostream>
#include <string>

using namespace std;


    #include <algorithm>
    

class Esperimento
{
private:
    string titolo;
    string scienziato;
    int tempo1;
    int tempo2;
    int tempo3;
    int costo;
    
public:
    Esperimento(string _titolo = "", string _scienziato = "", int _tempo1 = 0, int _tempo2 = 0, int _tempo3 = 0, int _costo = 0) : titolo(_titolo), scienziato(_scienziato), tempo1(_tempo1), tempo2(_tempo2), tempo3(_tempo3), costo(_costo) {}

    string getTitolo() const { return titolo; }
    void setTitolo(string v) { titolo = v; }

    string getScienziato() const { return scienziato; }
    void setScienziato(string v) { scienziato = v; }

    int getTempo1() const { return tempo1; }
    void setTempo1(int v) { tempo1 = v; }

    int getTempo2() const { return tempo2; }
    void setTempo2(int v) { tempo2 = v; }

    int getTempo3() const { return tempo3; }
    void setTempo3(int v) { tempo3 = v; }

    int getCosto() const { return costo; }
    void setCosto(int v) { costo = v; }

    

    bool operator==(const Esperimento& right) const { return titolo == right.titolo && scienziato == right.scienziato && tempo1 == right.tempo1 && tempo2 == right.tempo2 && tempo3 == right.tempo3 && costo == right.costo; }

friend ostream& operator<<(ostream& out, const Esperimento& x) { return out << "[" << x.titolo << ", " << x.scienziato << ", " << x.tempo1 << ", " << x.tempo2 << ", " << x.tempo3 << ", " << x.costo << "]"; }
};

#endif
