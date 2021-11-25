//
// Created by xyamix on 19.11.2021.
//

#include "AlgebraUtils.h"

Substitution::Substitution() {}

Substitution::Substitution(vector<string> substitution) {
  this->substitution = substitution;
}

Substitution &Substitution::operator=(const Substitution &A) {
  this->substitution = A.get_substitution();
  return *this;
}

bool Substitution::operator==(Substitution &A) {
  this->delete_empty();
  A.delete_empty();
  if (A.substitution[0] == "" && substitution[0] == "")
    return true;
  if (A.substitution.size() != substitution.size())
    return false;
  for (auto subs1 : substitution) {
    bool finded = false;
    for (auto subs2 : A.get_substitution()) {
      if (isEqual(subs1, subs2)) {
        finded = true;
      }
    }
    if (!finded)
      return false;
  }
  return true;
}

Substitution Substitution::operator*(Substitution &A) {
  vector<string> result;
  vector<int> used;
  string current_subs;
  int current = find_not_used(used); //****
  int start = current;
  used.push_back(current);
  current_subs += (char)current + '0';
  while (true) {
    int next_A = A.get_next(current);
    current = get_next(next_A);
    if (current == start) {
      if (current_subs.length() == 1) {
        current_subs = "";
      }
      result.push_back(current_subs);
      current = find_not_used(used);
      current_subs = (char)current + '0';
      used.push_back(current);
      start = current;
      if (current == -1) {
        current = A.find_not_used(used);
        current_subs = (char)current + '0';
        used.push_back(current);
        start = current;
        if (current == -1) {
          break;
        }
      }
    } else {
      current_subs += (char)current + '0';
      used.push_back(current);
    }
  }
  Substitution newSubstitution(result);
  newSubstitution.delete_empty();
  return newSubstitution;
}

vector<string> Substitution::get_substitution() const { return substitution; }

void Substitution::delete_empty() {
  if (substitution.size() > 1) {
    for (int i = 0; i < substitution.size(); i++) {
      if (substitution[i] == "") {
        substitution.erase(substitution.begin() + i);
      }
    }
  }
}

void Substitution::input() {
  string cycle;
  cin >> cycle;
  substitution.push_back(cycle);
}

void Substitution::print() {
  string line;
  for (auto subs : substitution) {
    line += "(" + subs + ")";
  }
  cout << line << endl;
}

bool Substitution::isEqual(string s1, string s2) {
  if (s1.length() != s2.length())
    return false;
  int first = s1[0] - '0';
  int index = get_element_index(first, s2);
  for (int i = 0; i < s1.length(); i++) {
    int next = index + i;
    if (next >= s2.length())
      next -= s2.length();
    if (s1[i] != s2[next]) {
      return false;
    }
  }
  return true;
}

int Substitution::find_not_used(vector<int> used) {
  for (int i = 0; i < substitution.size(); i++) {
    for (auto element : substitution[i]) {
      int current_element = element - '0';
      bool is_used = false;
      for (int j = 0; j < used.size(); j++) {
        if (current_element == used[j]) {
          is_used = true;
        }
      }
      if (!is_used) {
        return current_element;
      }
    }
  }
  return -1;
}

int Substitution::get_next(int k) {
  int current = k;
  for (int i = substitution.size() - 1; i >= 0; i--) {
    current = get_next_in_subs(current, substitution[i]);
  }
  return current;
}

int Substitution::get_next_in_subs(int k, const string subs) {
  int next_index = get_element_index(k, subs) + 1;
  if (next_index == -1) {
    return k;
  }
  if (next_index >= subs.length()) {
    next_index = subs.length() - next_index;
  }
  int res = subs[next_index] - '0';
  return res;
}

int Substitution::get_element_index(int k, const string subs) {
  for (int i = 0; i < subs.length(); i++) {
    int current_element = (int)subs[i] - '0';
    if (current_element == k) {
      return i;
    }
  }
  return -2;
}
