#include <iostream>
using namespace std;

int main() {
  int *A = new int(5);  // Intero inizializzato a 5
  int *B = new int[5];  // Array di 5 elementi interi, non inizializzati

  cout << *A << endl;  // 5
  cout << *B << endl;  // Spazzatura
}