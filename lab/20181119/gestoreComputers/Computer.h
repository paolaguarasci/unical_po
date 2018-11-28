#if !defined(COMPUTER_H)
#define COMPUTER_H

#include <string>

class Computer {
 private:
  std::string nome;
  std::string connessoA;

 public:
  Computer(){};
  Computer(const std::string& n, const std::string& c)
      : nome(n), connessoA(c) {}
  std::string getConnessoA() const { return connessoA; }
  void setConnessoA(std::string connessoA) { this->connessoA = connessoA; }
  const std::string& getNome() const { return nome; }
  void setNome(const std::string& nome) { this->nome = nome; }
  bool operator==(const Computer& p) const { return connessoA == p.connessoA; }
  bool operator<(const Computer& p) const { return connessoA < p.connessoA; }
  bool operator<=(const Computer& p) const { return connessoA <= p.connessoA; }
  bool operator>(const Computer& p) const { return connessoA > p.connessoA; }
  bool operator>=(const Computer& p) const { return connessoA >= p.connessoA; }
};
#endif  // COMPUTER_H
