
#ifndef Mobile_H_
#define Mobile_H_

#include <iostream>
#include <string>

using namespace std;


enum Tipo { TAVOLO = 0, SEDIA, COMODINO, ARMADIO };
#include <algorithm>
    

class Mobile
{
private:
    string nomeMobile;
    string produttore;
    int prezzo;
    Tipo tipo;
    string collaboratore;
    
public:
    Mobile(string _nomeMobile = "", string _produttore = "", int _prezzo = 0, Tipo _tipo = TAVOLO, string _collaboratore = "") : nomeMobile(_nomeMobile), produttore(_produttore), prezzo(_prezzo), tipo(_tipo), collaboratore(_collaboratore) {}

    string getNomeMobile() const { return nomeMobile; }
    void setNomeMobile(string v) { nomeMobile = v; }

    string getProduttore() const { return produttore; }
    void setProduttore(string v) { produttore = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    string getCollaboratore() const { return collaboratore; }
    void setCollaboratore(string v) { collaboratore = v; }

    

    bool operator==(const Mobile& right) const { return nomeMobile == right.nomeMobile && produttore == right.produttore && prezzo == right.prezzo && tipo == right.tipo && collaboratore == right.collaboratore; }

friend ostream& operator<<(ostream& out, const Mobile& x) { return out << "[" << x.nomeMobile << ", " << x.produttore << ", " << x.prezzo << ", " << x.tipo << ", " << x.collaboratore << "]"; }
};

#endif
