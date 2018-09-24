#include <iostream>
using namespace std;

int main()
{
    int a = 1, b = 2, x = 0, count = 0;
    do
    {
        x += a / b;
        count++;
    } while (x < 5); // ciclo infinito!

    cout << "-" << count << endl;
}
