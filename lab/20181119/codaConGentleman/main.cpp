#include "CodaConGentleman.h"

int main(int argc, char const *argv[]) {
  CodaConGentleman cg;

  cg.push_back(Persona("Uomo1", M));
  cg.push_back(Persona("Donna1", F));
  cg.push_back(Persona("Donna2", F));
  cg.push_back(Persona("Donna1", F));
  cg.push_back(Persona("Uomo3", M));
  cg.push_back(Persona("Donna2", F));
  cg.push_back(Persona("Uomo2", M));
  cg.push_back(Persona("Donna3", F));
  cg.push_back(Persona("Donna4", F));
  cg.push_back(Persona("Donna5", F));
  cg.push_back(Persona("Uomo2", M));
  cg.push_back(Persona("Donna6", F));
  cg.push_back(Persona("Uomo5", M));
  cg.push_back(Persona("Uomo6", M));
  cg.pop();
  cg.pop();
  cg.pop();
  cg.pop();
  cg.pop();
  cg.pop();
  cg.stampa();

  return 0;
}
