#include <string>
#include <algorithm>
#include <vector>
#include "../tripla/Tripla.h"

void stampaElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v);
bool aggiungiElettrodomestico( std::vector<Tripla<std::string, std::string, double> > &v, const Tripla<std::string, std::string, double> &t);
int numeroElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v);
int capacitaElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v);
void ordinaElettrodomestici( std::vector<Tripla<std::string, std::string, double> > &v);
Tripla<std::string, std::string, double> restituisciElettrodomesticoInPosizioneCentrale(const std::vector<Tripla<std::string, std::string, double> > &v);

int main(int argc, char const *argv[])
{
  std::vector<Tripla<std::string, std::string, double> > elettrodomestici;
  Tripla<std::string, std::string, double> t1("TV Led", "Sony", 899.00);
  Tripla<std::string, std::string, double> t2("TV Led", "Samsung", 799.00);
  Tripla<std::string, std::string, double> t3("TV Oled", "Sony", 500.00);

  aggiungiElettrodomestico(elettrodomestici, t1);
  aggiungiElettrodomestico(elettrodomestici, t2);
  aggiungiElettrodomestico(elettrodomestici, t3);
  aggiungiElettrodomestico(elettrodomestici, t1);
  stampaElettrodomestici(elettrodomestici);
  ordinaElettrodomestici(elettrodomestici);
  stampaElettrodomestici(elettrodomestici);

  restituisciElettrodomesticoInPosizioneCentrale(elettrodomestici).stampa();

  return 0;
}

void stampaElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v) {
  int size = v.size();
  for(size_t i = 0; i < size; i++) {
    std::cout << "Elettrodomestico " << i << " ";
    v[i].stampa();
    std::cout << std::endl;
  }
}
bool aggiungiElettrodomestico(std::vector<Tripla<std::string, std::string, double> > &v, const Tripla<std::string, std::string, double> &t) {
  if(std::find(v.begin(), v.end(), t) == v.end()) {v.push_back(t); return true;}
return false;
}
int numeroElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v) {
  return v.size();
}
int capacitaElettrodomestici(const std::vector<Tripla<std::string, std::string, double> > &v) {
  return v.capacity();
}
void ordinaElettrodomestici(std::vector<Tripla<std::string, std::string, double> > &v) {
  sort(v.begin(), v.end(), [] (Tripla<std::string, std::string, double> const& a, Tripla<std::string, std::string, double> const& b) {
    if( a.getOne() != b.getOne()) {return a.getOne() < b.getOne();}
    else if( a.getTwo() != b.getTwo()) {return a.getTwo() < b.getTwo();}
    else {return a.getThree() < b.getThree();}
  });
}
Tripla<std::string, std::string, double> restituisciElettrodomesticoInPosizioneCentrale(const std::vector<Tripla<std::string, std::string, double> > &v) {
  return v[(v.size() - 1) / 2];
}

