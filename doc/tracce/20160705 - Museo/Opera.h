
#ifndef Opera_H_
#define Opera_H_

#include <iostream>
#include <string>

using namespace std;


enum Tipo { QUADRO = 0, STATUA, EDIFICIO };
#include <algorithm>
#include <set>
#include <climits>
    

class Opera
{
private:
    string titolo;
    string artista;
    int x;
    int y;
    Tipo tipo;
    
public:
    Opera(string _titolo = "", string _artista = "", int _x = 0, int _y = 0, Tipo _tipo = QUADRO) : titolo(_titolo), artista(_artista), x(_x), y(_y), tipo(_tipo) {}

    string getTitolo() const { return titolo; }
    void setTitolo(string v) { titolo = v; }

    string getArtista() const { return artista; }
    void setArtista(string v) { artista = v; }

    int getX() const { return x; }
    void setX(int v) { x = v; }

    int getY() const { return y; }
    void setY(int v) { y = v; }

    Tipo getTipo() const { return tipo; }
    void setTipo(Tipo v) { tipo = v; }

    

    bool operator==(const Opera& right) const { return titolo == right.titolo && artista == right.artista && x == right.x && y == right.y && tipo == right.tipo; }

friend ostream& operator<<(ostream& out, const Opera& x) { return out << "[" << x.titolo << ", " << x.artista << ", " << x.x << ", " << x.y << ", " << x.tipo << "]"; }
};

#endif
