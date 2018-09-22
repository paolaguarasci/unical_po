
#ifndef Viaggio_H_
#define Viaggio_H_

#include <iostream>
#include <string>

using namespace std;


    enum Continente { AFRICA = 0, AMERICA, ASIA, EUROPA, OCEANIA };
    #include <algorithm>
    

class Viaggio
{
private:
    string destinazione;
    Continente continente;
    unsigned distanza;
    unsigned costo;
    unsigned prenotazioni;
    
public:
    Viaggio(string _destinazione = "", Continente _continente = AFRICA, unsigned _distanza = 0, unsigned _costo = 0, unsigned _prenotazioni = 0) : destinazione(_destinazione), continente(_continente), distanza(_distanza), costo(_costo), prenotazioni(_prenotazioni) {}

    string getDestinazione() const { return destinazione; }
    void setDestinazione(string v) { destinazione = v; }

    Continente getContinente() const { return continente; }
    void setContinente(Continente v) { continente = v; }

    unsigned getDistanza() const { return distanza; }
    void setDistanza(unsigned v) { distanza = v; }

    unsigned getCosto() const { return costo; }
    void setCosto(unsigned v) { costo = v; }

    unsigned getPrenotazioni() const { return prenotazioni; }
    void setPrenotazioni(unsigned v) { prenotazioni = v; }

    

    bool operator==(const Viaggio& right) const { return destinazione == right.destinazione && continente == right.continente && distanza == right.distanza && costo == right.costo && prenotazioni == right.prenotazioni; }

friend ostream& operator<<(ostream& out, const Viaggio& x) { return out << "[" << x.destinazione << ", " << x.continente << ", " << x.distanza << ", " << x.costo << ", " << x.prenotazioni << "]"; }
};

#endif
