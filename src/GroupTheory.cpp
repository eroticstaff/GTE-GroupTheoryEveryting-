//
// Created by xyamix on 19.11.2021.
//

#include "GroupTheory.h"

using namespace std;

////////////////////////////////
// Group
////////////////////////////////

template <typename T> Group<T>::Group(vector<T> elements, T e) {
  this->elements = elements;
  this->e = e;
}

template <typename T> Group<T>::Group() { this->e = (T)malloc(sizeof(T)); }

template <typename T> void Group<T>::getElementsOrder() {
  for (auto &element : elements) {
    T thisElement = element;
    for (int i = 0; i < MAX_ORDER_CHECK_COUNT; i++) {
      thisElement = thisElement * element;
      if (thisElement == e) {
        element.setOrder(i + 2);
        cout << "Order of " << element.name << " is " << i + 2 << endl;
        break;
      }
    }
  }
}

template <typename T>
bool Group<T>::check_if_the_parent(T element_parent, T element_dist) {
  char main_parent_name = element_parent.name[0];
  for (auto parent_name : element_parent.name) {
    if (main_parent_name != parent_name) {
      return false;
    }
  }
  for (auto child_name : element_dist.name) {
    if (child_name != main_parent_name) {
      return false;
    }
  }
  return true;
}

template <typename T> bool Group<T>::is_in_elements(T check_element) {
  if (check_element == e) {
    return true;
  }
  for (auto element : elements) {
    if (element == check_element) {
      return true;
    }
  }
  return false;
}

template <typename T> void Group<T>::generateGroup() {
  for (auto element : elements) {
    if (element.order > 2) {
      T newElement = element;
      for (int i = 0; i < element.order - 2; i++) {
        newElement = newElement * element;
        if (!is_in_elements(newElement))
          this->elements.push_back(newElement);
      }
    }
  }
  int size = elements.size();
  for (int i = 0; i < MAX_GENERATE_ITERATIONS; i++) {
    bool changed = false;
    for (int j = 0; j < size; j++) {
      for (int k = j; k < size; k++) {
        if (!check_if_the_parent(elements[j], elements[k])) {
          T newElement1 = elements[j] * elements[k];
          T newElement2 = elements[k] * elements[j];
          if (!is_in_elements(newElement1)) {
            elements.push_back(newElement1);
            changed = true;
          }
          if (!is_in_elements(newElement2)) {
            elements.push_back(newElement2);
            changed = true;
          }
        }
      }
    }
    if (!changed) {
      break;
    }
    size = elements.size();
  }
  printElements();
}

template <typename T> void Group<T>::printElements() {
  string group = "Group(E,";
  for (auto &element : elements) {
    cout << element.name << ":" << endl;
    element.print();
    group += element.name + ",";
  }
  group += ")";
  cout << group << endl;
}

template <typename T> Group<T> Group<T>::findCenter() {
  vector<T> newElements;
  for (int i = 0; i < elements.size(); i++) {
    bool isCenter = true;
    for (int j = 0; j < elements.size(); j++) {
      if (i != j) {
        T elem1 = elements[j] * elements[i];
        T elem2 = elements[i] * elements[j];
        if (elem1 != elem2) {
          isCenter = false;
        }
      }
    }
    if (isCenter) {
      newElements.push_back(elements[i]);
    }
  }
  Group<T> Center(newElements, e);
  Center.printElements();
  return Center;
}

template <typename T> void Group<T>::check_if_cycle() {
  for (auto element : elements) {
    if (element.order == elements.size()) {
      isCycle = true;
      break;
    }
  }
}

////////////////////////////////
// GroupElement
////////////////////////////////
void GroupElement::setOrder(int n) { this->order = n; }
////////////////////////////////
// MatrixGroupElement
////////////////////////////////

MatrixGroupElement::MatrixGroupElement(string name, Matrix &matrix)
    : matrix(matrix.getSize()) {
  this->name = name;
  this->matrix = matrix;
}

MatrixGroupElement
MatrixGroupElement::operator+(MatrixGroupElement &matrixGroupElement) {
  string newName = this->name + "+" + matrixGroupElement.name;
  Matrix newMatrix = this->matrix + matrixGroupElement.matrix;
  return MatrixGroupElement(newName, newMatrix);
}

MatrixGroupElement
MatrixGroupElement::operator*(MatrixGroupElement &matrixGroupElement) {
  string newName = this->name + matrixGroupElement.name;
  Matrix newMatrix = this->matrix * matrixGroupElement.matrix;
  return MatrixGroupElement(newName, newMatrix);
}

MatrixGroupElement &
MatrixGroupElement::operator=(const MatrixGroupElement &matrixGroupElement) {
  this->name = matrixGroupElement.name;
  this->matrix = matrixGroupElement.matrix;
  return *this;
}

bool MatrixGroupElement::operator==(MatrixGroupElement &matrixGroupElement) {
  bool result = this->matrix == matrixGroupElement.matrix;
  return result;
}

bool MatrixGroupElement::operator!=(MatrixGroupElement &matrixGroupElement) {
  bool result = this->matrix == matrixGroupElement.matrix;
  return !result;
}

void MatrixGroupElement::print() { this->matrix.print(); }

MatrixGroupElement::MatrixGroupElement() {}

MatrixGroupElement::MatrixGroupElement(void *) {}

////////////////////////////////
// SubstitutionGroupElement
////////////////////////////////

SubstitutionGroupElement::SubstitutionGroupElement(string name,
                                                   Substitution &substitution) {
  this->name = name;
  this->substitution = substitution;
}

SubstitutionGroupElement
SubstitutionGroupElement::operator*(SubstitutionGroupElement &substitution) {
  string newName = this->name + substitution.name;
  Substitution result = this->substitution * substitution.substitution;
  return SubstitutionGroupElement(newName, result);
}

SubstitutionGroupElement &SubstitutionGroupElement::operator=(
    const SubstitutionGroupElement &substitution) {
  this->substitution = substitution.substitution;
  this->name = substitution.name;
  return *this;
}

bool SubstitutionGroupElement::operator==(
    SubstitutionGroupElement &substitution) {
  return this->substitution == substitution.substitution;
}

bool SubstitutionGroupElement::operator!=(
    SubstitutionGroupElement &substitution) {
  return !(this->substitution == substitution.substitution);
}

void SubstitutionGroupElement::print() { substitution.print(); }

SubstitutionGroupElement::SubstitutionGroupElement() {}

SubstitutionGroupElement::SubstitutionGroupElement(void *pVoid) {}

template class Group<MatrixGroupElement>;
template class Group<SubstitutionGroupElement>;
