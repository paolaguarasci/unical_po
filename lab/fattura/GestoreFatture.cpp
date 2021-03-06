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
  std::vector<std::tuple<std::string, double>> somme;
  for (auto fattura : fatture) {
    std::string key = fattura.getEmettitrice();
    if (find_if(somme.begin(), somme.end(),
                [key](const std::tuple<std::string, double>& a) {
                  return std::get<0>(a) == key;
                }) == somme.end())
      somme.push_back(std::make_tuple(
          fattura.getEmettitrice(), getSommaEmesse(fattura.getEmettitrice())));
  }
  sort(somme.begin(), somme.end(),
       [](const std::tuple<std::string, double>& a,
          const std::tuple<std::string, double>& b) {
         return std::get<1>(a) > std::get<1>(b);
       });

  return std::get<1>(somme[0]) + std::get<1>(somme[1]);
}
int GestoreFatture::metodo10() {
  std::vector<std::tuple<std::string, double>> alimentare;
  std::vector<std::tuple<std::string, double>> sportivo;
  for (auto fattura : fatture) {
    std::string key = fattura.getEmettitrice();
    if (fattura.getTipoProdotto() == ALIMENTARE) {
      alimentare.push_back(std::make_tuple(key, fattura.getImporto()));
    }
    if (fattura.getTipoProdotto() == SPORTIVO) {
      sportivo.push_back(std::make_tuple(key, fattura.getImporto()));
    }
  }
  sort(alimentare.begin(), alimentare.end(),
       [](const std::tuple<std::string, double>& a,
          const std::tuple<std::string, double>& b) {
         return std::get<1>(a) > std::get<1>(b);
       });
  sort(sportivo.begin(), sportivo.end(),
       [](const std::tuple<std::string, double>& a,
          const std::tuple<std::string, double>& b) {
         return std::get<1>(a) < std::get<1>(b);
       });
  return countDaA(std::get<0>(alimentare[0]), std::get<0>(sportivo[0]));
}

std::string GestoreFatture::metodo11() {
  std::list<std::string> lista;
  for (auto fattura : fatture) {
    if (tipiDiversi(fattura.getEmettitrice()) == 1 &&
        fattura.getTipoProdotto() == ALIMENTARE)
      lista.push_back(fattura.getEmettitrice());
  }
  lista.sort();
  lista.unique();
  std::string result = "";
  for (auto a : lista) {
    result += a;
    result += ",";
  }
  return result.substr(0, result.length() - 1);
}
std::string GestoreFatture::metodo12() {
  std::vector<std::tuple<std::string, double>> apparizioni;
  for (auto fattura : fatture) {
    std::string key = fattura.getEmettitrice();
    if (find_if(apparizioni.begin(), apparizioni.end(),
                [key](const std::tuple<std::string, double>& a) {
                  return std::get<0>(a) == key;
                }) == apparizioni.end())
      apparizioni.push_back(
          std::make_tuple(fattura.getEmettitrice(),
                          countApparizioni(fattura.getEmettitrice())));
    key = fattura.getRicevente();
    if (find_if(apparizioni.begin(), apparizioni.end(),
                [key](const std::tuple<std::string, double>& a) {
                  return std::get<0>(a) == key;
                }) == apparizioni.end())
      apparizioni.push_back(std::make_tuple(
          fattura.getRicevente(), countApparizioni(fattura.getRicevente())));
  }
  sort(apparizioni.begin(), apparizioni.end(),
       [](const std::tuple<std::string, double>& a,
          const std::tuple<std::string, double>& b) {
         return std::get<1>(a) < std::get<1>(b);
       });
  std::string aziendaMenoPresente = std::get<0>(apparizioni[0]);
  std::vector<std::string> result;
  for (auto fattura : fatture) {
    if ((fattura.getEmettitrice() == aziendaMenoPresente) &&
        find(result.begin(), result.end(), fattura.getEmettitrice()) ==
            result.end()) {
      result.push_back(fattura.getRicevente());
    }
    if ((fattura.getRicevente() == aziendaMenoPresente) &&
        find(result.begin(), result.end(), fattura.getRicevente()) ==
            result.end()) {
      result.push_back(fattura.getEmettitrice());
    }
  }
  sort(result.begin(), result.end());
  std::string result_str = "";
  for (auto r : result) {
    result_str += r + ",";
  }
  return result_str.substr(0, result_str.length() - 1);
}
int GestoreFatture::metodo13() { return 0; }
int GestoreFatture::metodo14() { return 0; }
int GestoreFatture::metodo15() { return 0; }
int GestoreFatture::metodo16() { return 0; }
// UTILS //
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
double GestoreFatture::getSommaEmesse(const std::string& azienda) const {
  double sum = 0.0;
  for (auto fattura : fatture) {
    if (fattura.getEmettitrice() == azienda) sum += fattura.getImporto();
  }
  return sum;
}

int GestoreFatture::countDaA(const std::string& a, const std::string& b) const {
  int sum = 0;
  for (auto fattura : fatture) {
    if (fattura.getEmettitrice() == a && fattura.getRicevente() == b) sum++;
  }

  return sum;
}

int GestoreFatture::countApparizioni(const std::string& a) const {
  int sum = 0;
  for (auto fattura : fatture) {
    if (fattura.getEmettitrice() == a) {
      sum++;
      // std::cout << fattura.getEmettitrice() << " " << sum << std::endl;
    }
    if (fattura.getRicevente() == a) {
      sum++;
      // std::cout << fattura.getRicevente() << " " << sum << std::endl;
    }
  }

  return sum;
}