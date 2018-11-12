#include <iostream>
#include <list>

void riempiLista(std::list<int> &lista) {
  int n;
  std::cin >> n;
  int tmp;
  for (int i = 0; i < n; i++) {
    std::cin >> tmp;
    lista.push_back(tmp);
  }
}
void stampaLista(std::list<int> &lista) {
  std::list<int>::iterator iter = lista.begin();
  for (; iter != lista.end(); iter++) std::cout << (*iter) << ", ";
}
void stampaDimLista(const std::list<int> &lista) {
  std::cout << "Dimensione " << lista.size() << std::endl;
}
void stampaPrimoElemLista(const std::list<int> &lista) {
  std::cout << "Primo Elemento " << lista.front() << std::endl;
}
void stampaUltimoElemLista(const std::list<int> &lista) {
  std::cout << "Ultimo Elemento " << lista.back() << std::endl;
}
void stampaPenultimoElemLista(std::list<int> &lista) {
  std::list<int>::iterator iter = lista.end();
  iter--;
  iter--;
  std::cout << "Peniltimo Elemento " << (*iter) << std::endl;
}
void rimuovoDuplicati(std::list<int> &lista) {
  lista.sort();
  std::list<int>::iterator iter = std::unique(lista.begin(), lista.end());
  lista.erase(iter, lista.end());
}

int main(int argc, char const *argv[]) {
  std::list<int> lista;
  riempiLista(lista);
  stampaLista(lista);
  stampaDimLista(lista);
  stampaPrimoElemLista(lista);
  stampaUltimoElemLista(lista);
  stampaPenultimoElemLista(lista);
  rimuovoDuplicati(lista);
  stampaLista(lista);
  return 0;
}
