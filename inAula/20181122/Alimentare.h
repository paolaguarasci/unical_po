
#if !defined(ALIMENTARE_H)
#define ALIMENTARE_H
#include <iostream>
#include <string>
#include "Prodotto.h"
class Alimentare : public Prodotto {
 private:
  std::string scadenza;

 public:
  Alimentare(std::string _nome, std::string _scadenza)
      : Prodotto(_nome), scadenza(_scadenza) {}
  ~Alimentare() { std::cout << "Distruggo Alimentare" << std::endl; }
  std::string getTipo() override { return "Alimentare"; }
  void stampaNome() override { std::cout << Prodotto::nome; }
  std::string getScadenza() { return scadenza; }
};
#endif  // ALIMENTARE_H
