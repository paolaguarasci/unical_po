#include "CodaPazienti.h"

int main() {
  CodaPazienti cp;
  cp.push(Paziente("Mario Rossi", ROSSO));
  cp.push(Paziente("Michele Asd", BIANCO));
  cp.push(Paziente("Giuseppe Verdi", VERDE));
  cp.push(Paziente("Mario Rossi", ROSSO));
  cp.push(Paziente("Michele Bianchi", BIANCO));
  cp.push(Paziente("Giuseppe Mehh", VERDE));
  cp.push(Paziente("Mario Rossi", ROSSO));
  cp.push(Paziente("Michele Tho", BIANCO));
  cp.push(Paziente("Giuseppe Verdi", VERDE));

  cp.push(Paziente("Michele Bianchi", GIALLO));
  cp.stampa();
  cout << "Size " << cp.size();

  return 0;
}