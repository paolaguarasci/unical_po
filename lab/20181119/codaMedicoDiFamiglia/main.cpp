#include "CodaMedicoDiFamiglia.h"

int main(int argc, char const *argv[]) {
  CodaMedicoDiFamiglia cg;

  cg.push_back(Persona("Paziente1", PAZIENTE));
  cg.push_back(Persona("Paziente2", PAZIENTE));
  cg.push_back(Persona("Paziente1", PAZIENTE));
  cg.push_back(Persona("INFORMATORE3", INFORMATORE));
  cg.push_back(Persona("Paziente13", PAZIENTE));
  cg.push_back(Persona("INFORMATORE2", INFORMATORE));
  cg.push_back(Persona("Paziente3", PAZIENTE));
  cg.push_back(Persona("Paziente4", PAZIENTE));
  cg.push_back(Persona("Paziente5", PAZIENTE));
  cg.push_back(Persona("INFORMATORE2", INFORMATORE));
  cg.push_back(Persona("Paziente6", PAZIENTE));
  cg.push_back(Persona("INFORMATORE5", INFORMATORE));
  cg.push_back(Persona("INFORMATORE6", INFORMATORE));
  cout << cg.pop().getTipo() << endl;
  cg.stampa();

  return 0;
}
