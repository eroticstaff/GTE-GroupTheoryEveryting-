#include "GroupTheoryUtils.h"
#include <iostream>

using namespace std;

intModuleN::intModuleN(int k, int n) {
  this->k = k % n;
  this->n = n;
}

intModuleN intModuleN::operator*(intModuleN &another) {
  int new_k = (this->k + another.k) % this->n;
  intModuleN result(new_k, this->n);
  return result;
}

intModuleN &intModuleN::operator=(intModuleN &another) {
  this->k = another.k;
  this->n = another.n;
  return *this;
}

bool intModuleN::operator==(intModuleN &another) {
  if (this->k == another.k) {
    return true;
  }
  return false;
}

void intModuleN::print() { cout << "[" << this->k << "]" << endl; };

void intModuleN::input() {
  cout << "Print n:" << endl;
  cin >> this->n;
  cout << "Print k:" << endl;
  cin >> this->k;
}