#include "Mobilificio.h"

using namespace std;

int main(int argc, char const *argv[])
{
  Mobilificio mobiliere;
  /*
    string nomeMobile;
    string produttore;
    int prezzo;
    Tipo tipo;
    string collaboratore;
  */
  mobiliere.aggiungi(Mobile("a", "P1", 10, TAVOLO, "P2"));
  mobiliere.aggiungi(Mobile("y", "P2", 13, SEDIA, "P3"));
  mobiliere.aggiungi(Mobile("d", "P3", 15, TAVOLO, "P4"));
  mobiliere.aggiungi(Mobile("f", "P4", 12, ARMADIO, ""));
  mobiliere.aggiungi(Mobile("e", "P5", 5, ARMADIO, "P2"));
  mobiliere.aggiungi(Mobile("b", "P1", 19, SEDIA, ""));
  mobiliere.aggiungi(Mobile("c", "P2", 22, SEDIA, ""));
  mobiliere.aggiungi(Mobile("w", "P3", 11, TAVOLO, ""));
  mobiliere.aggiungi(Mobile("q", "P7", 2, TAVOLO, "P2"));
  mobiliere.aggiungi(Mobile("g", "P1", 10, TAVOLO, ""));
  mobiliere.aggiungi(Mobile("z", "P7", 3, TAVOLO, ""));
  cout << "Metodo1(): Prezzo massimo sotto la media                  " << mobiliere.metodo1() << endl;
  cout << "Metodo2(): Num mobili produttore economico                " << mobiliere.metodo2() << endl;
  cout << "Metodo3(): Differenza tra prod di sedie e prod di tavoli  " << mobiliere.metodo3() << endl;
  cout << "Metodo4(): Collaborazioni dell'ultimo produttore in lista " << mobiliere.metodo4() << endl;
  return 0;
}
