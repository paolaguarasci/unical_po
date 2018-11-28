#if !defined(ABBIGLIAMENTO_H)
#define ABBIGLIAMENTO_H
#include <iostream>
#include <string>
#include "Prodotto.h"
class Abbigliamento : public Prodotto {
 private:
  int taglia;

 public:
  Abbigliamento(std::string _nome, int _taglia)
      : Prodotto(_nome), taglia(_taglia) {}
  ~Abbigliamento() { std::cout << "Distruggo abbigliamento" << std::endl; }
  std::string getTipo() override { return "Abbigliamento"; }
  void stampaNome() override { std::cout << Prodotto::nome; }

  int getTaglia() { return taglia; }
};
#endif  // ABBIGLIAMENTO_H