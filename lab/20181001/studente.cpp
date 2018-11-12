#include <iostream>
#include <string>
using namespace std;
const int N_EXAM = 30;

class Studente {
  friend ostream &operator<<(ostream &, const Studente &);
  friend istream &operator>>(istream &, Studente &);

 private:
  string first__name = "undefined";
  string last__name = "undefined";
  int exam[N_EXAM] = {0};

 public:
  const string &getFirstName() const;
  const string &getLastName() const;
  void setFirstName(const string &new__first);
  void setLastName(const string &new__last);

  void addResult(int, int);
  double getAverage() const;
  int getExamToDo() const;
  int getExamDoes() const;
  int getMaxGrade() const;
  int getMinGrade() const;
};

int main() {
  Studente myAwesomeStud;
  cin >> myAwesomeStud;
  cout << myAwesomeStud;
  cout << "Average grade " << myAwesomeStud.getAverage() << endl;
  cout << "Exam does " << myAwesomeStud.getExamDoes() << endl;
  cout << "Exam To do " << myAwesomeStud.getExamToDo() << endl;
  cout << "Max grade " << myAwesomeStud.getMaxGrade() << endl;
  cout << "Min grade " << myAwesomeStud.getMinGrade() << endl;
  return 0;
}

ostream &operator<<(ostream &os, const Studente &toPrint) {
  os << toPrint.first__name << " " << toPrint.last__name << "\n";

  for (int i = 0; i < N_EXAM; i++) {
    if (toPrint.exam[i] >= 18) {
      os << "#" << i + 1 << " " << toPrint.exam[i] << endl;
    }
  }
  return os;
}

istream &operator>>(istream &is, Studente &toRead) {
  string first, last;
  is >> first >> last;
  toRead.setFirstName(first);
  toRead.setLastName(last);
  int tmp;
  for (int i = 0; i < N_EXAM; i++) {
    is >> tmp;
    toRead.addResult(i, tmp);
  }
  return is;
}

const string &Studente::getFirstName() const { return first__name; }
const string &Studente::getLastName() const { return last__name; }
void Studente::setFirstName(const string &new__first) {
  first__name = new__first;
}
void Studente::setLastName(const string &new__last) { last__name = new__last; }

void Studente::addResult(int exm, int grade) {
  if (grade >= 0 && grade <= N_EXAM) exam[exm] = grade;
}
double Studente::getAverage() const {
  double sum = 0.0;
  for (int i = 0; i < N_EXAM; i++) {
    sum += exam[i];
  }
  return sum / getExamDoes();
}
int Studente::getExamToDo() const {
  int examToDo = 0;
  for (int i = 0; i < N_EXAM; i++) {
    if (exam[i] == 0) examToDo++;
  }
  return examToDo;
}
int Studente::getExamDoes() const { return N_EXAM - getExamToDo(); }
int Studente::getMaxGrade() const {
  int max = 0;
  for (int i = 1; i < N_EXAM; i++) {
    if (exam[i] > exam[max]) max = i;
  }
  return exam[max];
}
int Studente::getMinGrade() const {
  int min = 0;
  for (int i = 0; i < N_EXAM; i++) {
    if (exam[i] >= 18) {
      min = i;
      break;
    }
  }
  for (int i = min + 1; i < N_EXAM; i++) {
    if (exam[i] >= 18 && exam[i] < exam[min]) min = i;
  }
  return exam[min];
}
