#include "Contatto.h"
Contatto::Contatto() {}
Contatto::Contatto(const string &nom, const string &cog)
    : nome(nom), cognome(cog) {}
Contatto::Contatto(const string &nom, const string &cog, const string &tel,
                   const string &em)
    : nome(nom), cognome(cog), telefono(tel), email(em) {}
ostream &operator<<(ostream &out, const Contatto &c) {
  out << c.nome << " -";
  out << c.cognome << " -";
  out << c.telefono << " -";
  out << c.email << endl;
  return out;
}
istream &operator>>(istream &in, Contatto &c) {
  cout << "Inserire il nome" << endl;
  in >> c.nome;
  cout << "Inserire il cognome" << endl;
  in >> c.cognome;
  cout << "Inserire l'indirizzo email" << endl;
  in >> c.email;
  cout << "Inserire il numero di telefono" << endl;
  in >> c.telefono;
  return in;
}
bool Contatto::operator==(const Contatto &c) const {
  return this->nome == c.nome && this->cognome == c.cognome &&
         this->email == c.email && this->telefono == c.telefono;
}
bool Contatto::operator!=(const Contatto &c) const {
  return this->nome != c.nome || this->cognome != c.cognome ||
         this->email != c.email || this->telefono != c.telefono;
  // Oppure return !(*this==c);
}
bool Contatto::operator<(const Contatto &c) const {
  if (cognome < c.cognome) return true;
  if (nome < c.nome) return true;
  return false;
}
bool Contatto::operator>(const Contatto &c) const {
  if (cognome > c.cognome) return true;
  if (nome > c.nome) return true;
  return false;  // Oppure return (*this)!=c && !((*this)<c);
}
const string &Contatto::getCognome() const { return cognome; }
const string &Contatto::getEmail() const { return email; }
const string &Contatto::getNome() const { return nome; }
const string &Contatto::getTelefono() const { return telefono; }
void Contatto::setNome(const string &nom) { nome = nom; }
void Contatto::setCognome(const string &cog) { cognome = cog; }
void Contatto::setEmail(const string &email) { this->email = email; }
void Contatto::setTelefono(const string &telefono) {
  this->telefono = telefono;
}