#include "ListaOrdinata.h"

int main(int argc, char const *argv[]) {
  ListaOrdinata lo;
  lo.push("asr");
  lo.push("rrf");
  lo.push("atr");

  lo.stampa();
  cout << "Size " << lo.size();

  return 0;
}
