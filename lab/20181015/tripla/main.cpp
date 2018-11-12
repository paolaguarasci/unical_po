
#include "Tripla.h"

int main() {
  Tripla<int, float, char> tripla(5, 5.5, 'a');
  // tripla.leggi();
  tripla.stampa();
  std::cout << tripla << std::endl;
  return 0;
}
