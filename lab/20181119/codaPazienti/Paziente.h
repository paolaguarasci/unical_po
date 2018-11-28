#ifndef PAZIENTE_H
#define PAZIENTE_H
#include <iostream>
#include <string>
using namespace std;
enum CodiceUrgenza { BIANCO = 0, VERDE, GIALLO, ROSSO };
class Paziente {
 private:
  string nome;
  CodiceUrgenza codice;

 public:
  Paziente() : nome(""), codice(BIANCO) {}
  Paziente(string n, CodiceUrgenza c) : nome(n), codice(c) {}
  CodiceUrgenza getCodice() const { return codice; }
  void setCodice(CodiceUrgenza codice) { this->codice = codice; }
  const string& getNome() const { return nome; }
  void setNome(const string& nome) { this->nome = nome; }
  bool operator==(const Paziente& p) const { return codice == p.codice; }
  bool operator<(const Paziente& p) const { return codice < p.codice; }
  bool operator<=(const Paziente& p) const { return codice <= p.codice; }
  bool operator>(const Paziente& p) const { return codice > p.codice; }
  bool operator>=(const Paziente& p) const { return codice >= p.codice; }
};
#endif