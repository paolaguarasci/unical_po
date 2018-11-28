#include <iostream>
#include "GestoreComputers.h"

using namespace std;

int main(int argc, char const *argv[]) {
  GestoreComputers gc;
  gc.push_back({"C1", "C2"});
  gc.push_back({"C2", "C1"});
  gc.push_back({"C3", ""});
  gc.push_back({"C4", "C3"});
  gc.push_back({"C5", ""});
  cout << gc.countConnessi() << endl;
  return 0;
}
