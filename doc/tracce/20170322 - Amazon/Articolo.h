
#ifndef Articolo_H_
#define Articolo_H_

#include <iostream>
#include <string>

using namespace std;


    enum Recensione { NESSUNA = 0, UNA_STELLA, DUE_STELLE, TRE_STELLE, QUATTRO_STELLE, CINQUE_STELLE };
    enum Spedizione { AMAZON_PRIME = 0, AMAZON_STANDARD, ALTRO };
    #include <algorithm>
    

class Articolo
{
private:
    string nome;
    string venditore;
    int prezzo;
    Recensione recensione;
    Spedizione spedizione;
    
public:
    Articolo(string _nome = "", string _venditore = "", int _prezzo = 0, Recensione _recensione = NESSUNA, Spedizione _spedizione = AMAZON_PRIME) : nome(_nome), venditore(_venditore), prezzo(_prezzo), recensione(_recensione), spedizione(_spedizione) {}

    string getNome() const { return nome; }
    void setNome(string v) { nome = v; }

    string getVenditore() const { return venditore; }
    void setVenditore(string v) { venditore = v; }

    int getPrezzo() const { return prezzo; }
    void setPrezzo(int v) { prezzo = v; }

    Recensione getRecensione() const { return recensione; }
    void setRecensione(Recensione v) { recensione = v; }

    Spedizione getSpedizione() const { return spedizione; }
    void setSpedizione(Spedizione v) { spedizione = v; }

    

    bool operator==(const Articolo& right) const { return nome == right.nome && venditore == right.venditore && prezzo == right.prezzo && recensione == right.recensione && spedizione == right.spedizione; }

friend ostream& operator<<(ostream& out, const Articolo& x) { return out << "[" << x.nome << ", " << x.venditore << ", " << x.prezzo << ", " << x.recensione << ", " << x.spedizione << "]"; }
};

#endif
