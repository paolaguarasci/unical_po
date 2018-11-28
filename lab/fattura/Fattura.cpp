#include "Fattura.h"

std::ostream& operator<<(std::ostream& os, const Fattura& fattura) {
  os << fattura.emettitrice << ", " << fattura.ricevente << ", "
     << fattura.importo << "€"
     << ", ";

  switch (fattura.prod){
    case 0:
      os << "Alimentare";
      break;
    case 1:
      os << "Sportivo";
      break;
    case 2:
      os << "Culturale";
      break;
    default:
      os << "Non specificato";
      break;
  }
  while (true) {
    
  }
  return os;
}