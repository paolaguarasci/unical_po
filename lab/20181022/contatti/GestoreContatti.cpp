#include "GestoreContatti.h"
#include <iostream>
#include <vector>
GestoreContatti::GestoreContatti() {}
GestoreContatti::~GestoreContatti() {}

void GestoreContatti::stampaContatti()
{
  std::list<Contatto>::iterator iter = contatti.begin();
  for (; iter != contatti.end(); iter++)
    std::cout << (*iter);
}
bool GestoreContatti::inserisciContatto(const Contatto &c)
{
  std::list<Contatto>::iterator iter = contatti.begin();
  for (; iter != contatti.end(); iter++)
    if (((*iter).getCognome() == c.getCognome()) && ((*iter).getNome() == c.getNome()) && ((*iter).getEmail() == c.getEmail()) && ((*iter).getTelefono() == c.getTelefono()))
      return false;
  contatti.push_back(c);
  return true;
}
int GestoreContatti::numeroContatti()
{
  return contatti.size();
}
void GestoreContatti::ordinaContatti()
{
  contatti.sort([](const Contatto &a, const Contatto &b) { return a.getCognome() < b.getCognome(); });
}
bool GestoreContatti::eliminaContattoConRemove(const Contatto &c)
{
  contatti.erase(std::remove(contatti.begin(), contatti.end(), c), contatti.end());
  return true;
}
std::vector<std::string> GestoreContatti::trovaNumeri(const std::string &nome, const std::string &cognome)
{
  std::vector<std::string> numeri;
  std::list<Contatto>::iterator iter = contatti.begin();
  for (; iter != contatti.end(); iter++)
  {
    if (((*iter).getCognome() == cognome) && ((*iter).getNome() == nome))
    {
      numeri.push_back((*iter).getTelefono());
    }
  }
  std::cout << "Numeri " << numeri.size() << std::endl;
  return numeri;
}
std::string GestoreContatti::trovaCognomePiuFrequente(int &freq)
{
  ordinaContatti();
  int maxCounter = 0;
  std::string cognomeFreq = (*contatti.begin()).getCognome();
  int tmpCounter = 0;
  std::list<Contatto>::iterator iter = contatti.begin();
  std::list<Contatto>::iterator succ = contatti.begin();
  for (; iter != contatti.end(); iter++)
  {
    succ++;
    if (succ != contatti.end() && (*iter).getCognome() == (*succ).getCognome())
    {
      tmpCounter++;
    }
    else
    {
      tmpCounter = 1;
    }

    if (tmpCounter > maxCounter)
    {
      maxCounter = tmpCounter;
      cognomeFreq = (*iter).getCognome();
      freq = tmpCounter;
    }
  }
  return cognomeFreq;
}
bool GestoreContatti::verificaDueContattiStessoTelefono()
{
  std::list<Contatto>::iterator iter1 = contatti.begin();
  std::list<Contatto>::iterator iter2 = contatti.begin();
  for (; iter1 != contatti.end(); iter1++)
  {
    for (; iter2 != contatti.end(); iter2++)
    {
      if (((*iter1).getTelefono() == (*iter2).getTelefono()) &&
          (((*iter1).getCognome() != (*iter2).getCognome()) ||
           ((*iter1).getNome() != (*iter2).getNome())))
        return true;
    }
  }
  return false;
}