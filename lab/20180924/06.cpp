#include <iostream>
using namespace std;

int main()
{
    char *X[20];

    for (int i = 0; i < 20; i++)
    {
        X[i] = new char[10];
    }

    // // Utilizzo

    for (int i = 0; i < 20; i++)
    {
        delete[] X[i];
    }
}