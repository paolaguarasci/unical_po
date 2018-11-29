#include "GestoreFatture.h"
using namespace std;

int main(int argc, char const *argv[]) {
  GestoreFatture gf;

  gf.aggiungi(Fattura("Azienda1", "Azienda2", 1, SPORTIVO));
  gf.aggiungi(Fattura("Azienda2", "Azienda1", 12, CULTURALE));
  gf.aggiungi(Fattura("Azienda3", "Azienda4", 2, ALIMENTARE));
  gf.aggiungi(Fattura("Azienda1", "Azienda8", 34, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda5", 2, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda5", 2, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda6", 154, SPORTIVO));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 5, CULTURALE));
  gf.aggiungi(Fattura("Azienda1", "Azienda5", 10, CULTURALE));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 0.006, CULTURALE));
  gf.aggiungi(Fattura("Azienda4", "Azienda1", 60, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda2", 990, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda2", 124, SPORTIVO));
  gf.aggiungi(Fattura("Azienda2", "Azienda4", 0.56, CULTURALE));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 23.12, SPORTIVO));
  gf.aggiungi(Fattura("Azienda3", "Azienda1", 90, ALIMENTARE));
  gf.aggiungi(Fattura("Azienda1", "Azienda6", 0.22, CULTURALE));

  // cout << gf;

  cout << "maxAziendaEmettitrice: " << gf.maxAziendaEmettitrice() << endl;
  cout << "aziendaFatturaMaggiore: " << gf.aziendaFatturaMaggiore() << endl;
  cout << "aziendaFatturaMinore: " << gf.aziendaFatturaMinore() << endl;
  cout << "aziendaMediaInOutMax: " << gf.aziendaMediaInOutMax() << endl;
  cout << "aziendeMonoProdotto: " << gf.aziendeMonoProdotto() << endl;
  cout << "diffAziendeMonoSportMonoCult: " << gf.diffAziendeMonoSportMonoCult()
       << endl;
  cout << "vendeAlimCompraSport: " << gf.vendeAlimCompraSport() << endl;
  cout << "nonCompraCult: " << gf.nonCompraCult() << endl;
  cout << "sommaImportiFattureEmessePrimaESeconda: "
       << gf.sommaImportiFattureEmessePrimaESeconda() << endl;
  cout << "Metodo 10: " << gf.metodo10() << endl;
  cout << "Metodo 11: " << gf.metodo11() << endl;
  cout << "Metodo 12: " << gf.metodo12() << endl;
  cout << "Metodo 13: " << gf.metodo13() << endl;
  cout << "Metodo 14: " << gf.metodo14() << endl;
  cout << "Metodo 15: " << gf.metodo15() << endl;
  cout << "Metodo 16: " << gf.metodo16() << endl;

  return 0;
}
