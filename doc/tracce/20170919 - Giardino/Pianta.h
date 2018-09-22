
#ifndef Pianta_H_
#define Pianta_H_

#include <iostream>
#include <string>

using namespace std;


#include <climits>
#include <list>

enum Tipo { CESPUGLIO = 0, ARBUSTO, RAMPICANTE };
    

class Pianta
{
private:
    string genere;
    Tipo tipo;
    int temperaturaMinima;
    int prezzo;
    
public:
    Pianta(string _genere = "", Tipo _tipo = CESPUGLIO, int _temperaturaMinima = 0, int _prezzo = 0) : genere(_genere), tipo(_tipo), temperaturaMinima(_temperaturaMinima), prezzo(_prezzo) {}

    string getGenere() const { return genere; }
    void setGenere(string v) { genere = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    int getTemperaturaMinima() const { return temperaturaMinima; }
    void setTemperaturaMinima(int v) { temperaturaMinima = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    

    bool operator==(const Pianta& right) const { return genere == right.genere && tipo == right.tipo && temperaturaMinima == right.temperaturaMinima && prezzo == right.prezzo; }

friend ostream& operator<<(ostream& out, const Pianta& x) { return out << "[" << x.genere << ", " << x.tipo << ", " << x.temperaturaMinima << ", " << x.prezzo << "]"; }
};

#endif
