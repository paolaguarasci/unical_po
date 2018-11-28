#if !defined(PRENOTAZIONE_H)
#define PRENOTAZIONE_H
#include <iostream>
#include <string>
#include "Doppia.h"
#include "Singola.h"
#include "Suite.h"
#include "Tripla.h"

class Prenotazione {
 private:
  std::string nome;
  std::string cognome;
  std::string cc;
  Camera* camera = nullptr;
  bool colazione;
  int costo;

 public:
  Prenotazione(std::string _nome, std::string _cognome, std::string _cc,
               bool _colazione, Camera* _camera)
      : nome(_nome),
        cognome(_cognome),
        cc(_cc),
        colazione(_colazione),
        camera(_camera) {}
  // ~Prenotazione() {
  //   std::cout << "\nDeleto la camera prenotata...\n";
  //   delete camera;
  // }
  int getTotale() const { return camera->calcolaCosto() + (colazione * 10); }
  int getTipo() const { return camera->tipologia(); }
  std::string getCognome() const { return cognome; }
};

#endif  // PRENOTAZIONE_H
