#include <iostream>
#include <string>
using namespace std;
const int NSTUD = 100;

class Corso {
  friend ostream &operator<<(ostream &, const Corso &);
  friend istream &operator>>(istream &, Corso &);

 public:
  // Corso(string n): nome(n), semestre(1), elenco(nullptr), size(0) {}
  // I costruttori che hanno un solo parametro devono essere usati con
  // 'explicit' SENZA explicit permette la conversione CON permette la
  // conversione implicita
  Corso(const string & = " ", int = 0, int * = nullptr, int = 0);
  Corso(const Corso &);
  ~Corso();
  const Corso &operator=(const Corso &);

  void add(int matricola);
  void del(int matricola);
  const Corso &sort();
  int getIndiceMatricola(int);

  int operator[](int);
  const int operator[](int) const;

 private:
  // dal c++ 11 posso inizializzare qui!
  // se non c'è alcun costruttore, uso questi dati
  // ha priorità il costruttore
  // Attenzione:
  // lista di inizializzazione nel costruttore evita la perdita di riferimenti
  // a memoria dinamica inizializzata qui (perchè c'è il rischio di memory leak)
  int semestre;
  string nome;
  int *matricole;
  int size, capacity;
  void aumentaDim();
  void swap(int, int);
};

// MAIN DI PROVA //
int main() {
  Corso progObj;
  cin >> progObj;
  cout << progObj << endl << endl;
  cout << progObj.sort();
  progObj.add(1222);
  cout << progObj;
  progObj.del(12345);
  cout << progObj;
}
///////////////////
std::ostream &operator<<(std::ostream &os, const Corso &toPrint) {
  os << "SEM: " << toPrint.semestre << " Corso: \"" << toPrint.nome
     << "\" Studenti iscritti: " << toPrint.size << endl;
  for (int i = 0; i < toPrint.size; i++) os << toPrint[i] << "\n";
  return os;
}
std::istream &operator>>(std::istream &is, Corso &toRead) {
  string nome;
  int semestre;
  int nstud;
  getline(is, nome);
  is >> semestre >> nstud;
  int *matTmp = new int[nstud];
  for (int i = 0; i < nstud; i++) {
    is >> matTmp[i];
  }
  toRead = Corso(nome, semestre, matTmp, nstud);
  delete[] matTmp;
  return is;
}

Corso::Corso(const string &n, int s, int *mat, int nStud) {
  nome = n;
  semestre = s;
  size = nStud;
  capacity = size * 2;
  matricole = new int[size];
  for (int i = 0; i < size; i++) matricole[i] = mat[i];
}
Corso::Corso(const Corso &toCopy) {
  nome = toCopy.nome;
  semestre = toCopy.semestre;
  size = toCopy.size;
  capacity = size * 1.5;
  matricole = new int[capacity];
  for (int i = 0; i < size; i++) this->matricole[i] = toCopy.matricole[i];
}
Corso::~Corso() { delete[] matricole; }

const Corso &Corso::operator=(const Corso &rhs) {
  if (this != &rhs) {
    delete[] matricole;
    nome = rhs.nome;
    semestre = rhs.semestre;
    size = rhs.size;
    capacity = size * 1.5;
    matricole = new int[capacity];
    for (int i = 0; i < size; i++) this->matricole[i] = rhs.matricole[i];
  }
  return *this;
}

void Corso::add(int nuovaMatricola) {
  if (size == capacity) aumentaDim();
  matricole[size++] = nuovaMatricola;
  sort();
}
void Corso::del(int matricola) {
  sort();
  int indice = getIndiceMatricola(matricola);
  matricole[indice] = matricole[size - 1] + 1;
  sort();
  size--;
}
const Corso &Corso::sort() {
  // Implementiamo un semplice bubble sort nemmeno tanto ottimizzato
  int lastSwapped = size;
  int countNSwap = 0;
  bool isSwap = true;
  for (int j = 0; j < size; j++) {
    for (int i = 0; i < size - 1; i++) {
      if (matricole[i] > matricole[i + 1]) {
        swap(i, i + 1);
        countNSwap++;
      }
    }
  }

  cout << "Numero di swap effettuati: " << countNSwap << endl;
  return *this;
}

void Corso::swap(int a, int b) {
  int tmp = matricole[a];
  matricole[a] = matricole[b];
  matricole[b] = tmp;
}
int Corso::getIndiceMatricola(int matricola) {
  for (int i = 0; i < size; i++) {
    if (matricole[i] == matricola) return i;
  }
  return -1;
}

int Corso::operator[](int indice) { return matricole[indice]; }
const int Corso::operator[](int indice) const { return matricole[indice]; }

void Corso::aumentaDim() {
  if (capacity != 0)
    capacity *= 2;
  else
    capacity = 10;
  int *tmp = new int[capacity];
  for (int i = 0; i < size; i++) tmp[i] = matricole[i];
  delete[] matricole;
  matricole = tmp;
}