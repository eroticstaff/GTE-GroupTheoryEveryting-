//
// Created by xyamix on 19.11.2021.
//

#ifndef GROUPTHEORY_GROUPTHEORY_H
#define GROUPTHEORY_GROUPTHEORY_H

#include "LinearAlgebra.h"
#include "AlgebraUtils.h"
#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>

#define MAX_ORDER_CHECK_COUNT 10
#define MAX_GENERATE_ITERATIONS 10


using namespace std;

class GroupElement {
public:
    string name;
    int order = -1;

    void setOrder(int n);
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

class SubstitutionGroupElement : public GroupElement{
private:
    Substitution substitution;
public:
    SubstitutionGroupElement();
    SubstitutionGroupElement(string name, Substitution &substitution);
    SubstitutionGroupElement operator*(SubstitutionGroupElement &substitution);
    SubstitutionGroupElement &operator=(const SubstitutionGroupElement &substitution);
    bool operator==(SubstitutionGroupElement &substitution);
    bool operator!=(SubstitutionGroupElement &substitution);
    void print();

    SubstitutionGroupElement(void *pVoid);
};

template<typename T>
class Group {
public:
    vector<T> elements;
    T e;
    string name;

    Group();
    Group(vector<T> elements, T e);
    void getElementsOrder();
    bool check_if_the_parent(T element_parent, T element_dist);
    bool is_in_elements(T check_element);
    void generateGroup();
    void printElements();
    Group findCenter();
};



#endif //GROUPTHEORY_GROUPTHEORY_H
