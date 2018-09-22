
#ifndef Prodotto_H_
#define Prodotto_H_

#include <iostream>
#include <string>

using namespace std;


    enum Categoria { ALTRO = 0, MACELLERIA, ORTOFRUTTA, PESCHERIA, PROFUMERIA };
    #include <algorithm>
    

class Prodotto
{
private:
    string nome;
    Categoria categoria;
    string rivenditore;
    unsigned costo;
    
public:
    Prodotto(string _nome = "", Categoria _categoria = ALTRO, string _rivenditore = "", unsigned _costo = 0) : nome(_nome), categoria(_categoria), rivenditore(_rivenditore), costo(_costo) {}

    string getNome() const { return nome; }
    void setNome(string v) { nome = v; }

    Categoria getCategoria() const { return categoria; }
    void setCategoria(Categoria v) { categoria = v; }

    string getRivenditore() const { return rivenditore; }
    void setRivenditore(string v) { rivenditore = v; }

    unsigned getCosto() const { return costo; }
    void setCosto(unsigned v) { costo = v; }

    

    bool operator==(const Prodotto& right) const { return nome == right.nome && categoria == right.categoria && rivenditore == right.rivenditore && costo == right.costo; }

friend ostream& operator<<(ostream& out, const Prodotto& x) { return out << "[" << x.nome << ", " << x.categoria << ", " << x.rivenditore << ", " << x.costo << "]"; }
};

#endif
