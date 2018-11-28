#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;
enum Tipo { INFORMATORE = 0, PAZIENTE };
class Persona {
 private:
  string nome;
  Tipo t;

 public:
  Persona() : nome(""), t(PAZIENTE) {}
  Persona(string n, Tipo t) : nome(n), t(t) {}
  Tipo getTipo() const { return t; }
  void setTipo(Tipo t) { this->t = t; }
  const string& getNome() const { return nome; }
  void setNome(const string& nome) { this->nome = nome; }
  //   bool operator==(const Persona& p) const { return codice == p.codice; }
  //   bool operator<(const Persona& p) const { return codice < p.codice; }
  //   bool operator<=(const Persona& p) const { return codice <= p.codice; }
  //   bool operator>(const Persona& p) const { return codice > p.codice; }
  //   bool operator>=(const Persona& p) const { return codice >= p.codice; }
};
#endif