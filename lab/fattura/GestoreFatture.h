#if !defined(GESTOREFATTURE_H)
#define GESTOREFATTURE_H

#include <algorithm>
#include <list>
#include "Fattura.h"

class GestoreFatture {
  friend std::ostream& operator<<(std::ostream&, GestoreFatture& gf);

 public:
  GestoreFatture(){};
  void aggiungi(const Fattura& f) { fatture.push_front(f); }

  // metodi strani //
  std::string maxAziendaEmettitrice() const;
  std::string aziendaFatturaMaggiore() const;
  std::string aziendaFatturaMinore() const;
  std::string aziendaMediaInOutMax() const;
  int aziendeMonoProdotto() const;
  int diffAziendeMonoSportMonoCult() const;
  int vendeAlimCompraSport() const;
  int nonCompraCult() const;
  double sommaImportiFattureEmessePrimaESeconda() const;

  // utils
  double getMediaEmesse(const std::string&) const;
  double getMediaRicevute(const std::string& azienda) const;
  int tipiDiversi(const std::string& azienda) const;
  bool compraAlmenoUno(const std::string& azienda, const PRODOTTO& prod) const;

 private:
  std::list<Fattura> fatture;
};

#endif  // GESTOREFATTURE_H
