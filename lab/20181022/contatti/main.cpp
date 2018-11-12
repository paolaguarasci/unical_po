#include <string>
#include <vector>
#include "GestoreContatti.h"

int main(int argc, char const *argv[]) {
  Contatto a("Michele", "Rossi", "12345", "email");
  Contatto b("Michele", "Verdi", "12345", "email");
  Contatto c("Michele", "Verdi", "12345", "email");
  Contatto d("Michele", "Verdi", "12345", "email");
  Contatto e("Michele", "Rossi", "12345", "email");
  Contatto f("Michele", "Verdi", "12345", "email");
  Contatto g("Michele", "Bianchi", "12345", "email");
  Contatto h("Andrea", "Rossi", "23456", "email");
  Contatto i("Giuseppe", "Verdi", "123456", "email");
  GestoreContatti gc;
  gc.inserisciContatto(b);
  gc.inserisciContatto(d);
  gc.inserisciContatto(e);
  gc.inserisciContatto(f);
  gc.inserisciContatto(g);
  gc.inserisciContatto(h);
  gc.inserisciContatto(c);
  gc.inserisciContatto(i);
  gc.inserisciContatto(a);
  int freq = 0;
  std::vector<std::string> numSigRossi = gc.trovaNumeri("Michele", "Rossi");
  for (int i = 0; i < numSigRossi.size(); i++)
    std::cout << numSigRossi[i] << std::endl;
  std::cout << gc.trovaCognomePiuFrequente(freq) << " " << freq << std::endl;
  std::cout << (gc.verificaDueContattiStessoTelefono() ? "SI" : "NO");
  gc.stampaContatti();
  return 0;
}
