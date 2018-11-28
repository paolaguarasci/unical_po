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

  for (std::vector<std::tuple<std::string, int>>::iterator frequenza =
           frequenze.begin();
       frequenza != frequenze.end(); frequenza++) {
    std::string key = std::get<0>(*frequenza);
    std::vector<std::tuple<std::string, int>>::iterator pos =
        find(frequenze.begin(), frequenze.end(),
             [key](const std::tuple<std::string, int>& a) {
               return std::get<0>(a) == key;
             });
    if (pos == frequenze.end()) {
      frequenze.push_back(std::make_tuple(frequenza->getEmettitrice(), 1));
    } else {
      //
    }
  }

  return std::get<0>(frequenze[0]);
}
std::string GestoreFatture::aziendaFatturaMaggiore() const { return ""; }
std::string GestoreFatture::aziendaFatturaMinore() const { return ""; }
std::string GestoreFatture::aziendaMediaInOutMax() const { return ""; }
int GestoreFatture::aziendeMonoProdotto() const { return 0; }
int GestoreFatture::diffAziendeMonoSportMonoCult() const { return 0; }
int GestoreFatture::vendeAlimCompraSport() const { return 0; }
int GestoreFatture::nonCompraCult() const { return 0; }
double GestoreFatture::sommaImportiFattureEmessePrimaESeconda() const {
  return 0;
}