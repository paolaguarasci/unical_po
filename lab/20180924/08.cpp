#include <iostream>
using namespace std;

int main()
{
    int *p1 = new int(20);
    short *p2 = new short[20];
    char **p3 = new char *[20];
    unsigned *p4[20];
    // bool *p5[20] = new bool[20]; ERRORE di compilazione
    // double **p6 = new double[20][20]; ERRORE di compilazione

    delete p1;
    delete[] p2;
    delete[] p3;
}