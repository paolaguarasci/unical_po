#include "GestoreFatture.h"
using namespace std;

int main(int argc, char const *argv[]) {
  GestoreFatture gf;

  gf.aggiungi(Fattura("Azienda1", "Azienda2", 1, SPORTIVO));
  gf.aggiungi(Fattura("Azienda2", "Azienda1", 12, SPORTIVO));
  gf.aggiungi(Fattura("Azienda3", "Azienda4", 2, SPORTIVO));
  gf.aggiungi(Fattura("Azienda1", "Azienda8", 34, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda5", 2, SPORTIVO));
  gf.aggiungi(Fattura("Azienda4", "Azienda6", 154, SPORTIVO));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 5, CULTURALE));
  gf.aggiungi(Fattura("Azienda1", "Azienda5", 10, CULTURALE));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 6, CULTURALE));
  gf.aggiungi(Fattura("Azienda4", "Azienda1", 60, CULTURALE));
  gf.aggiungi(Fattura("Azienda4", "Azienda2", 990, CULTURALE));
  gf.aggiungi(Fattura("Azienda4", "Azienda2", 124, CULTURALE));
  gf.aggiungi(Fattura("Azienda2", "Azienda4", 0.56, ALIMENTARE));
  gf.aggiungi(Fattura("Azienda2", "Azienda3", 23.12, ALIMENTARE));
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

  return 0;
}
