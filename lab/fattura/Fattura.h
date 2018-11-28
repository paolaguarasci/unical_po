/*
La classe deve modellare almeno le seguenti informazioni riguardanti una
Fattura:
- il nome dell'azienda che ha emesso la fattura;
- il nome dell'azienda che ha ricevuto la fattura;
- l'importo della fattura (può essere anche negativo);
- il tipo del prodotto venduto (per semplicità si assumano 3 possibili valori:
ALIMENTARE, SPORTIVO, CULTURALE).
*/

#if !defined(FATTURA_H)
#define FATTURA_H

#include <iostream>
#include <string>
enum PRODOTTO { ALIMENTARE, SPORTIVO, CULTURALE };
class Fattura {
  friend std::ostream& operator<<(std::ostream&, const Fattura&);

 private:
  std::string emettitrice;
  std::string ricevente;
  double importo;
  PRODOTTO prod;

 public:
  Fattura(std::string e, std::string r, double i, PRODOTTO p)
      : emettitrice(e), ricevente(r), importo(i), prod(p) {}

  std::string getEmettitrice() const { return emettitrice; }
  std::string getRicevente() const { return ricevente; }
  double getImporto() const { return importo; }
  PRODOTTO getTipoProdotto() const { return prod; }
};

#endif  // FATTURA_H
