#include <iostream>
using namespace std;

int main()
{
    char *X[20];
    char **matrice = new char *[20];
    for (int i = 0; i < 20; i++)
    {
        matrice[i] = new char[10];
    }

    // Utilizzo

    for (int i = 0; i < 20; i++)
    {
        delete[] matrice[i];
    }

    delete[] matrice;
}