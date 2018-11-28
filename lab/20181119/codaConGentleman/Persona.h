#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
#include <string>
using namespace std;
enum Sesso { M = 0, F };
class Persona {
 private:
  string nome;
  Sesso sex;

 public:
  Persona() : nome(""), sex(M) {}
  Persona(string n, Sesso c) : nome(n), sex(c) {}
  Sesso getSesso() const { return sex; }
  void setSesso(Sesso s) { this->sex = s; }
  const string& getNome() const { return nome; }
  void setNome(const string& nome) { this->nome = nome; }
  //   bool operator==(const Persona& p) const { return codice == p.codice; }
  //   bool operator<(const Persona& p) const { return codice < p.codice; }
  //   bool operator<=(const Persona& p) const { return codice <= p.codice; }
  //   bool operator>(const Persona& p) const { return codice > p.codice; }
  //   bool operator>=(const Persona& p) const { return codice >= p.codice; }
};
#endif