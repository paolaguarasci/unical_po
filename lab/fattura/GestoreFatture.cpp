#include "GestoreFatture.h"
#include <algorithm>
#include <iostream>
#include <list>
#include <string>
#include <tuple>
#include <vector>
std::ostream& operator<<(std::ostream& os, GestoreFatture& gf) {
  for (std::list<Fattura>::iterator it = gf.fatture.begin();
       it != gf.fatture.end(); it++) {
    os << (*it) << std::endl;
  }
  return os;
}
std::string GestoreFatture::maxAziendaEmettitrice() const {
  std::vector<std::tuple<std::string, int>> frequenze;
  for (std::list<Fattura>::const_iterator fattura = fatture.begin();
       fattura != fatture.end(); fattura++) {
    std::string key = fattura->getEmettitrice();
    std::vector<std::tuple<std::string, int>>::iterator pos =
        find_if(frequenze.begin(), frequenze.end(),
                [key](const std::tuple<std::string, int>& a) {
                  return std::get<0>(a) == key;
                });
    if (pos == frequenze.end()) {
      frequenze.push_back(std::make_tuple(fattura->getEmettitrice(), 1));
    } else {
      int dist = std::distance(frequenze.begin(), pos);
      std::get<1>(frequenze[dist]) += 1;
    }
  }
  sort(frequenze.begin(), frequenze.end(),
       [](const std::tuple<std::string, int>& a,
          const std::tuple<std::string, int>& b) {
         return std::get<1>(a) > std::get<1>(b);
       });

  return std::get<0>(frequenze[0]);
}
std::string GestoreFatture::aziendaFatturaMaggiore() const {
  Fattura fatturaMaggiore = fatture.front();
  for (auto fattura : fatture) {
    if (fatturaMaggiore.getImporto() < fattura.getImporto())
      fatturaMaggiore = fattura;
  }

  return fatturaMaggiore.getEmettitrice();
}
std::string GestoreFatture::aziendaFatturaMinore() const {
  Fattura fatturaMinore = fatture.front();
  for (auto fattura : fatture) {
    if (fatturaMinore.getImporto() > fattura.getImporto())
      fatturaMinore = fattura;
  }

  return fatturaMinore.getEmettitrice();
}
std::string GestoreFatture::aziendaMediaInOutMax() const {
  std::vector<std::tuple<std::string, double>> medie;
  for (auto fattura : fatture) {
    std::string key = fattura.getEmettitrice();
    std::vector<std::tuple<std::string, double>>::iterator pos =
        find_if(medie.begin(), medie.end(),
                [key](const std::tuple<std::string, double>& a) {
                  return std::get<0>(a) == key;
                });
    if (pos == medie.end()) {
      medie.push_back(
          std::make_tuple(fattura.getEmettitrice(),
                          getMediaEmesse(fattura.getEmettitrice()) -
                              getMediaRicevute(fattura.getEmettitrice())));
    }
  }
  sort(medie.begin(), medie.end(),
       [](const std::tuple<std::string, double>& a,
          const std::tuple<std::string, double>& b) {
         return std::get<1>(a) > std::get<1>(b);
       });

  return std::get<0>(medie[0]);
}
int GestoreFatture::aziendeMonoProdotto() const {
  std::vector<std::string> aziendeMono;
  for (auto fattura : fatture) {
    if (tipiDiversi(fattura.getEmettitrice()) == 1 &&
        (find(aziendeMono.begin(), aziendeMono.end(),
              fattura.getEmettitrice()) == aziendeMono.end())) {
      aziendeMono.push_back(fattura.getEmettitrice());
    }
  }
  return aziendeMono.size();
}
int GestoreFatture::diffAziendeMonoSportMonoCult() const {
  std::vector<std::string> aziendeCultura;
  std::vector<std::string> aziendeSportive;
  for (auto fattura : fatture) {
    if (tipiDiversi(fattura.getEmettitrice()) == 1 &&
        fattura.getTipoProdotto() == CULTURALE &&
        (find(aziendeCultura.begin(), aziendeCultura.end(),
              fattura.getEmettitrice()) == aziendeCultura.end())) {
      aziendeCultura.push_back(fattura.getEmettitrice());
    } else if (tipiDiversi(fattura.getEmettitrice()) == 1 &&
               fattura.getTipoProdotto() == SPORTIVO &&
               (find(aziendeSportive.begin(), aziendeSportive.end(),
                     fattura.getEmettitrice()) == aziendeSportive.end())) {
      aziendeSportive.push_back(fattura.getEmettitrice());
    }
  }

  return aziendeSportive.size() - aziendeCultura.size();
}
int GestoreFatture::vendeAlimCompraSport() const {
  std::vector<std::string> aziende;
  for (auto fattura : fatture) {
    if (tipiDiversi(fattura.getEmettitrice()) == 1 &&
        fattura.getTipoProdotto() == ALIMENTARE &&
        find(aziende.begin(), aziende.end(), fattura.getEmettitrice()) ==
            aziende.end() &&
        compraAlmenoUno(fattura.getEmettitrice(), SPORTIVO)) {
      aziende.push_back(fattura.getEmettitrice());
    }
  }
  return aziende.size();
}
int GestoreFatture::nonCompraCult() const {
  std::vector<std::string> aziende;
  for (auto fattura : fatture) {
    if (find(aziende.begin(), aziende.end(), fattura.getRicevente()) ==
            aziende.end() &&
        !compraAlmenoUno(fattura.getRicevente(), CULTURALE)) {
      aziende.push_back(fattura.getRicevente());
    }
  }
  return aziende.size();
}
double GestoreFatture::sommaImportiFattureEmessePrimaESeconda() const {
  return 0;
}

double GestoreFatture::getMediaEmesse(const std::string& azienda) const {
  double sum = 0.0;
  int count = 0;
  for (auto fattura : fatture) {
    if (fattura.getEmettitrice() == azienda) sum += fattura.getImporto();
    count++;
  }
  return sum / count;
}
double GestoreFatture::getMediaRicevute(const std::string& azienda) const {
  double sum = 0.0;
  int count = 0;
  for (auto fattura : fatture) {
    if (fattura.getRicevente() == azienda) sum += fattura.getImporto();
    count++;
  }
  return sum / count;
}

int GestoreFatture::tipiDiversi(const std::string& azienda) const {
  std::vector<PRODOTTO> tipi;
  for (auto fattura : fatture) {
    if (fattura.getEmettitrice() == azienda &&
        find(tipi.begin(), tipi.end(), fattura.getTipoProdotto()) ==
            tipi.end()) {
      tipi.push_back(fattura.getTipoProdotto());
    }
  }
  return tipi.size();
}

bool GestoreFatture::compraAlmenoUno(const std::string& azienda,
                                     const PRODOTTO& prod) const {
  for (auto fattura : fatture) {
    if (fattura.getRicevente() == azienda && fattura.getTipoProdotto() == prod)
      return true;
  }
  return false;
}