#if !defined(PRODOTTO_H)
#define PRODOTTO_H
#include <string>
class Prodotto {
 protected:
  std::string nome;

 public:
  Prodotto(std::string _nome) : nome(_nome) {}
  virtual ~Prodotto() { std::cout << "Distruggo Prodotto" << std::endl; }
  virtual std::string getTipo() { return "Prodotto"; }
  virtual void stampaNome() { std::cout << "il nome del prodotto..."; }
  // std::string getScadenza() { return "Scadenza non definita"; }
};
#endif  // PRODOTTO_H
