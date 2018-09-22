
#ifndef Atleta_H_
#define Atleta_H_

#include <iostream>
#include <string>

using namespace std;


    #include <climits>
    

class Atleta
{
private:
    string atleta;
    string nazione;
    int eta;
    int numeroOri;
    int numeroArgenti;
    int numeroBronzi;
    
public:
    Atleta(string _atleta = "", string _nazione = "", int _eta = 20, int _numeroOri = 0, int _numeroArgenti = 0, int _numeroBronzi = 0) : atleta(_atleta), nazione(_nazione), eta(_eta), numeroOri(_numeroOri), numeroArgenti(_numeroArgenti), numeroBronzi(_numeroBronzi) {}

    string getAtleta() const { return atleta; }
    void setAtleta(string v) { atleta = v; }

    string getNazione() const { return nazione; }
    void setNazione(string v) { nazione = v; }

    int getEta() const { return eta; }
    void setEta(int v) { eta = v; }

    int getNumeroOri() const { return numeroOri; }
    void setNumeroOri(int v) { numeroOri = v; }

    int getNumeroArgenti() const { return numeroArgenti; }
    void setNumeroArgenti(int v) { numeroArgenti = v; }

    int getNumeroBronzi() const { return numeroBronzi; }
    void setNumeroBronzi(int v) { numeroBronzi = v; }

    

    bool operator==(const Atleta& right) const { return atleta == right.atleta && nazione == right.nazione && eta == right.eta && numeroOri == right.numeroOri && numeroArgenti == right.numeroArgenti && numeroBronzi == right.numeroBronzi; }

friend ostream& operator<<(ostream& out, const Atleta& x) { return out << "[" << x.atleta << ", " << x.nazione << ", " << x.eta << ", " << x.numeroOri << ", " << x.numeroArgenti << ", " << x.numeroBronzi << "]"; }
};

#endif
