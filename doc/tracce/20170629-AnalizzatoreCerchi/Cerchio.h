
#ifndef Cerchio_H_
#define Cerchio_H_

#include <iostream>
#include <string>

using namespace std;


    #include <algorithm>
    #include <climits>
    #include <cmath>
    

class Cerchio
{
private:
    int x;
    int y;
    int raggio;
    
public:
    Cerchio(int _x = 0, int _y = 0, int _raggio = 0) : x(_x), y(_y), raggio(_raggio) {}

    int getX() const { return x; }
    void setX(int v) { x = v; }

    int getY() const { return y; }
    void setY(int v) { y = v; }

    int getRaggio() const { return raggio; }
    void setRaggio(int v) { raggio = v; }

    

    bool operator==(const Cerchio& right) const { return x == right.x && y == right.y && raggio == right.raggio; }

friend ostream& operator<<(ostream& out, const Cerchio& x) { return out << "[" << x.x << ", " << x.y << ", " << x.raggio << "]"; }
};

#endif
