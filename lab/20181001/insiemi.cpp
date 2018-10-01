// Esercizio 01
#include <iostream>
using namespace std;

class Set
{
  friend ostream &operator<<(ostream &, const Set &);
  friend istream &operator>>(istream &, Set &);

private:
  int valoreMassimo;
  bool *insieme;
  int findValoreMassimo(int *, size_t);
  void init();

public:
  Set();
  Set(const Set &);
  Set(int *, int);
  ~Set();
  const Set &operator=(const Set &);

  void cambiaDimensione(int);
  void aggiungiElemento(int);
  Set unione(const Set &);
  Set intersezione(const Set &);
};

ostream &operator<<(ostream &os, const Set &toPrint)
{
  os << "{";
  for (size_t i = 0; i < toPrint.valoreMassimo + 1; i++)
  {
    if (toPrint.insieme[i] && i != toPrint.valoreMassimo)
    {
      os << i << ", ";
    }
    else if (toPrint.insieme[i] && i == toPrint.valoreMassimo)
    {
      os << i;
    }
  }
  os << "}";
  return os;
}
istream &operator>>(istream &is, Set &toRead)
{
  int dim;
  is >> dim;
  int *tmp = new int[dim]();
  for (size_t i = 0; i < dim; i++)
  {
    is >> tmp[i];
  }

  toRead = Set(tmp, dim);
  delete[] tmp;
  return is;
}

int Set::findValoreMassimo(int *list, size_t dim)
{
  int max = 0;
  for (size_t i = 0; i < dim; i++)
  {
    if (list[i] > list[max])
    {
      max = i;
    }
  }
  return list[max];
}
void Set::init()
{
  for (size_t i = 0; i < valoreMassimo + 1; i++)
  {
    insieme[i] = false;
  }
}

Set::Set() : valoreMassimo(0), insieme(0) {}
Set::Set(const Set &toCopy)
{
  valoreMassimo = toCopy.valoreMassimo;
  insieme = new bool[valoreMassimo + 1];
  init();
  for (size_t i = 0; i < valoreMassimo + 1; i++)
  {
    insieme[i] = toCopy.insieme[i];
  }
}
Set::Set(int *list, int dim)
{
  valoreMassimo = findValoreMassimo(list, dim);
  insieme = new bool[valoreMassimo + 1];
  init();
  for (size_t i = 0; i < dim; i++)
  {
    insieme[list[i]] = true;
  }
}
Set::~Set()
{
  delete[] insieme;
}
const Set &Set::operator=(const Set &rhs)
{
  if (this != &rhs)
  {
    delete[] insieme;
    valoreMassimo = rhs.valoreMassimo;
    insieme = new bool[valoreMassimo + 1];
    init();
    for (size_t i = 0; i < valoreMassimo + 1; i++)
    {
      insieme[i] = rhs.insieme[i];
    }
  }
  return *this;
}

void Set::cambiaDimensione(int nuovaDim)
{
  if (valoreMassimo == 0)
  {
    valoreMassimo = nuovaDim;
    insieme = new bool[valoreMassimo + 1];
    init();
  }
  else
  {
    bool *arrTmp = new bool[nuovaDim];
    for (size_t i = 0; i < nuovaDim; i++)
    {
      if (i < valoreMassimo + 1)
      {
        arrTmp[i] = insieme[i];
      }
      else
      {
        arrTmp[i] = false;
      }
    }
    valoreMassimo = nuovaDim;
    delete[] insieme;
    insieme = arrTmp;
  }
}
void Set::aggiungiElemento(int nuovoElemento)
{
  if (nuovoElemento > valoreMassimo)
  {
    cambiaDimensione(nuovoElemento);
  }
  insieme[nuovoElemento] = true;
}
Set Set::unione(const Set &altroInsieme)
{
  const Set *big = this;
  const Set *small = &altroInsieme;

  if (this->valoreMassimo < altroInsieme.valoreMassimo)
  {
    big = &altroInsieme;
    small = this;
  }
  Set tmp;
  for (size_t i = 0; i < (big->valoreMassimo) + 1; i++)
  {
    if (i < (small->valoreMassimo) + 1)
    {
      if (small->insieme[i] || big->insieme[i])
      {
        tmp.aggiungiElemento(i);
      }
    }
    else
    {
      if (big->insieme[i])
      {
        tmp.aggiungiElemento(i);
      }
    }
  }
  return tmp;
}

Set Set::intersezione(const Set &altroInsieme)
{
  const Set *big = this;
  const Set *small = &altroInsieme;

  if (this->valoreMassimo < altroInsieme.valoreMassimo)
  {
    big = &altroInsieme;
    small = this;
  }
  Set tmp;
  for (size_t i = 0; i < (small->valoreMassimo) + 1; i++)
  {
    if (small->insieme[i] && big->insieme[i])
    {
      tmp.aggiungiElemento(i);
    }
  }
  return tmp;
}

// MAIN //
int main()
{
  // Set set;
  // cin >> set;
  // cout << set << endl;
  // set.aggiungiElemento(3);
  // cout << set << endl;
  // set.aggiungiElemento(100);
  // cout << set << endl;

  // cout << endl;
  // cout << endl;

  Set A;
  cin >> A;
  Set B;
  cin >> B;
  cout << "A " << A << endl;
  cout << "B " << B << endl;
  Set C = A.unione(B);
  cout << "A \u222a B " << C << endl;
  Set D = A.intersezione(B);
  cout << "A \u2229 B " << D << endl;

  return 0;
}