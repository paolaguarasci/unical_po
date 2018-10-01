#include <iostream>
#include <string>
using namespace std;

class Studente
{
  friend ostream &operator<<(ostream &, const Studente &);
  friend istream &operator>>(istream &, Studente &);

private:
  string first__name = "undefined";
  string last__name = "undefined";
  int exam[30] = {0};

public:
  const string &getFirstName() const;
  const string &getLastName() const;
  void setFirstName(const string &new__first) const;
  void setLasfName(const string &new__last) const;

  void addResult(int);
  double getAverage() const;
  int getExamToDo() const;
  int getExamDoes() const;
  int getMaxGrade() const;
  int getMinGrade() const;
};

int main()
{
  return 0;
}
