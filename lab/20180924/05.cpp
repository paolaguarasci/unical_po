#include <iostream>
using namespace std;

void f(int x, int &y)
{
    if (x > 0)
    {
        x -= 1;
        f(x, y);
    }
    else
    {
        x = y;
        y--;
    }
}

int main()
{
    int x = 5, y = 6;
    f(x, y);
    cout << x << '-' << y << endl; // 5-5
}