#include <iostream>
#include <vector>
#include "Abbigliamento.h"
#include "Alimentare.h"
#include "Editoria.h"
#include "Prodotto.h"
using namespace std;

int main() {
  // Editoria ed("Giornale", 2);
  // Alimentare al("Uovo", "domani");

  // al.stampaNome();  // Uovo
  // al.nome = "Ciao"; // non compila, correttamente
  // cout << " " << al.getScadenza() << endl;  // domani
  // cout << Abbigliamento("Pantaloni", 40).getTaglia() << endl << endl;  // 40

  vector<Prodotto *> scaffale;

  scaffale.push_back(new Alimentare("Bistecca", "Tra Dieci giorni"));
  scaffale.push_back(new Editoria("Vice", 200));
  scaffale.push_back(new Abbigliamento("Giaccone", 46));

  for (vector<Prodotto *>::iterator it = scaffale.begin(); it != scaffale.end();
       it++) {
    // con il dinamyc binding posso accedere ai metodi della classe base,
    // specializzati nelle classi derivare ma NON ai metodi specifici delle
    // classi derivate

    // questo non compila per esempio:
    // if ((*it).getTipo() ==
    // "Alimentare") {
    //   cout << " " << (*(*it)).getScadenza();
    // }

    // questo si perchè getTipo() esiste, virtual, nella classe Prodotti
    // e, a runtime, restituisce il tipo dell'oggetto specializzato
    cout << (*it)->getTipo();
    cout << endl;
  }
  for (auto *i : scaffale) {
    delete i;
  }
  return 0;
}