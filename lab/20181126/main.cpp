#include <iostream>
#include "GestoreHotel.h"
#include "Prenotazione.h"

int main() {
  GestoreHotel gh;
  gh.addRoom(new Singola());
  gh.addRoom(new Singola());
  gh.addRoom(new Doppia());
  gh.addRoom(new Tripla());
  gh.addRoom(new Suite());

  Singola* ss = new Singola();
  Prenotazione p("Ciccio", "Pasticcio", "cartaDiCredito", false, ss);
  gh.addReservation(p);
  gh.stampaResoconto();
  gh.removeReservation("Pasticcio");
  gh.stampaResoconto();

  delete ss;
  return 0;
}
