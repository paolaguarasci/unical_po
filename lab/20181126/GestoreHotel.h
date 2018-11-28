#if !defined(GESTOREHOTEL_H)
#define GESTOREHOTEL_H
#include <iostream>
#include <list>
#include <string>
#include "Doppia.h"
#include "Prenotazione.h"
#include "Singola.h"
#include "Suite.h"
#include "Tripla.h"
class GestoreHotel {
 private:
  std::list<Camera*> camere;
  std::list<Prenotazione> prenotazioni;

 public:
  GestoreHotel() {}
  void addRoom(Camera* _camera) { camere.push_back(_camera); }
  bool addReservation(const Prenotazione& pp) {
    // controllare che ci siano ancora camere disponibili di tipo "tipologia"
    // eventualmente prenotare (aggiungendo la prenotazione alla lista delle
    // prenotazioni)
    if (getCamereDisp(pp.getTipo()) > 0) {
      prenotazioni.push_back(pp);
      return true;
    }
    return false;
  }
  bool removeReservation(std::string cognome) {
    // rimuovere la prenotazione del cliente "cognome"
    std::list<Prenotazione>::iterator pos = find_if(
        prenotazioni.begin(), prenotazioni.end(),
        [cognome](const Prenotazione& a) { return a.getCognome() == cognome; });
    if (pos == prenotazioni.end()) return false;
    prenotazioni.erase(pos);
    return true;
  }
  int getReservationTotal(const Prenotazione& pp) { return pp.getTotale(); }
  int getAllReservation() {
    int sum = 0;
    // calcolare il costo delle prenotazioni
    for (std::list<Prenotazione>::iterator it = prenotazioni.begin();
         it != prenotazioni.end(); it++)
      sum += it->getTotale();
    return sum;
  }
  int getCamere(int tipo) {
    int sum = 0;
    for (std::list<Camera*>::iterator it = camere.begin(); it != camere.end();
         it++)
      if ((*it)->tipologia() == tipo) sum++;
    return sum;
  }
  int getCamereDisp(int tipo) { return getCamere(tipo) - getRes(tipo); }
  int getRes(int tipo) {
    int sum = 0;
    for (std::list<Prenotazione>::iterator it = prenotazioni.begin();
         it != prenotazioni.end(); it++)
      if (it->getTipo() == tipo) sum++;
    return sum;
  }
  void stampaResoconto() {
    std::cout << "\nCamere singole: " << getCamere(1) << " di cui prenotate "
              << getRes(1) << " e libere " << getCamereDisp(1) << std::endl;
    std::cout << "Camere doppie: " << getCamere(2) << " di cui prenotate "
              << getRes(2) << " e libere " << getCamereDisp(2) << std::endl;
    std::cout << "Camere triple: " << getCamere(3) << " di cui prenotate "
              << getRes(3) << " e libere " << getCamereDisp(3) << std::endl;
    std::cout << "Camere suite: " << getCamere(4) << " di cui prenotate "
              << getRes(4) << " e libere " << getCamereDisp(4) << std::endl;
  }

  ~GestoreHotel() {
    // for (std::list<Prenotazione>::iterator it = prenotazioni.begin();
    //      it != prenotazioni.end(); it++)
    //   delete *it;
    for (std::list<Camera*>::iterator it = camere.begin(); it != camere.end();
         it++)
      delete *it;
  }
};
#endif  // GESTOREHOTEL_H
