#include <iostream>
using namespace std;

class Rettangolo
{
  friend ostream &operator<<(ostream &, const Rettangolo &);
  friend istream &operator>>(istream &, Rettangolo &);

private:
  float width = 1.0;
  float height = 1.0;
  bool checkDim(float);

public:
  Rettangolo();
  Rettangolo(float);
  Rettangolo(float, float);

  float getWidth() const;
  float getHeight() const;
  void setWidth(float newWidth);
  void setHeight(float newHeight);

  float side() const;
  float area() const;
};

int main()
{
  Rettangolo a;
  cin >> a;
  cout << a;
  return 0;
}

ostream &operator<<(ostream &os, const Rettangolo &toPrint)
{
  int h = toPrint.height * 100 / 100;
  int w = toPrint.width * 100 / 100;

  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      os << "*";
    }
    os << "\n";
  }
  return os;
}
istream &operator>>(istream &is, Rettangolo &toRead)
{
  float h, w;
  is >> h >> w;
  toRead = Rettangolo(w, h);
  return is;
}

bool Rettangolo::checkDim(float dim)
{
  return dim > 1.0 && dim < 10.0;
}

Rettangolo::Rettangolo() {}
Rettangolo::Rettangolo(float w)
{
  setWidth(w);
}
Rettangolo::Rettangolo(float w, float h)
{
  setWidth(w);
  setHeight(h);
}
float Rettangolo::getWidth() const { return width; }
float Rettangolo::getHeight() const { return height; }
void Rettangolo::setWidth(float w)
{
  if (checkDim(w))
    width = w;
}
void Rettangolo::setHeight(float h)
{
  if (checkDim(h))
    height = h;
}

float Rettangolo::side() const
{
  return height * 2 + width * 2;
}
float Rettangolo::area() const
{
  return height * width;
}