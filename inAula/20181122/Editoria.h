#if !defined(EDITORIA_H)
#define EDITORIA_H
#include <iostream>
#include <string>
#include "Prodotto.h"
class Editoria : public Prodotto {
 public:
  Editoria(std::string _nome, int _vol) : Prodotto(_nome), volume(_vol) {}
  ~Editoria() { std::cout << "Distruggo editoria" << std::endl; }
  std::string getTipo() override { return "Editoria"; }
  void stampaNome() override { std::cout << Prodotto::nome; };
  int getVolume() { return volume; }

 private:
  int volume;
};
#endif  // EDITORIA_H
