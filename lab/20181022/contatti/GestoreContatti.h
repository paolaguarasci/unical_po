#ifndef GESTORECONTATTI_H
#define GESTORECONTATTI_H

#include "Contatto.h"
#include <list>
class GestoreContatti
{
public:
  GestoreContatti();
  ~GestoreContatti();

  void stampaContatti();
  bool inserisciContatto(const Contatto &c);
  int numeroContatti();
  void ordinaContatti();
  bool eliminaContattoConRemove(const Contatto &c);
  std::vector<std::string> trovaNumeri(const string &nome, const string &cognome);
  std::string trovaCognomePiuFrequente(int &freq);
  bool verificaDueContattiStessoTelefono();

private:
  std::list<Contatto> contatti;
};
#endif //GESTORECONTATTI_H