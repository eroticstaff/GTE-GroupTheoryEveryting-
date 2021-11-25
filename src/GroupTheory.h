//
// Created by xyamix on 19.11.2021.
//

#ifndef GROUPTHEORY_GROUPTHEORY_H
#define GROUPTHEORY_GROUPTHEORY_H

#include "AlgebraUtils.h"
#include "GroupTheoryUtils.h"
#include "LinearAlgebra.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

#define MAX_ORDER_CHECK_COUNT 10
#define MAX_GENERATE_ITERATIONS 10

using namespace std;

enum templateGroup {
  S1,
  S2,
  S3,
  S4,
};

class GroupElement {
public:
  string name;
  int order = -1;

  void setOrder(int n);
};

/*
Main group abstract class
For all groups operation is designed as *
Element shoud have such methods as:
- operator*
- operator=
- operator==
- void print()

*/
template <typename T> class Group {
public:
  vector<T> elements; // all elements
  T e;                // e element of the group
  string name;        // name of the group
  bool isCycle;       // bool that says if the group is a cycle group

  Group();                        // group initialize
  Group(vector<T> elements, T e); // main group initialize
  void getElementsOrder();        // get element order
  bool check_if_the_parent(
      T element_parent,
      T element_dist); // tmp function for checking if the element already was
                       // used when generating
  bool
  is_in_elements(T check_element); // check if element is already in elements
  void generateGroup();  // generate group by elements that were initialized
  void printElements();  // print group elements
  void check_if_cycle(); // checking if group is cycle
  Group findCenter();    // find group center
};

class MatrixGroupElement : public GroupElement {
private:
  Matrix matrix;

public:
  MatrixGroupElement();
  MatrixGroupElement(void *pVoid);
  MatrixGroupElement(string name, Matrix &matrix);
  MatrixGroupElement operator+(MatrixGroupElement &matrixGroupElement);
  MatrixGroupElement operator*(MatrixGroupElement &matrixGroupElement);
  MatrixGroupElement &operator=(const MatrixGroupElement &matrixGroupElement);
  bool operator==(MatrixGroupElement &matrixGroupElement);
  bool operator!=(MatrixGroupElement &matrixGroupElement);
  void print();
};

class SubstitutionGroupElement : public GroupElement {
private:
  Substitution substitution;

public:
  SubstitutionGroupElement();
  SubstitutionGroupElement(string name, Substitution &substitution);
  SubstitutionGroupElement operator*(SubstitutionGroupElement &substitution);
  SubstitutionGroupElement &
  operator=(const SubstitutionGroupElement &substitution);
  bool operator==(SubstitutionGroupElement &substitution);
  bool operator!=(SubstitutionGroupElement &substitution);
  void print();

  SubstitutionGroupElement(void *pVoid);
};

#endif // GROUPTHEORY_GROUPTHEORY_H
