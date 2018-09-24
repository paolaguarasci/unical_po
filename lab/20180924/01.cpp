#include <iostream>
using namespace std;

bool f(int v[], int lun, int x)
{
    for (int i = 0; i < lun; i++)
        if (v[i] == x)
            return true;
        else

            return false;
}

int main()
{
    int v[4] = {11, 21, 13, 4};
    int x = 21;
    int lun = 4;
    // Restituisce "False"
    cout << (f(v, lun, x) ? "True" : "False") << endl;
}