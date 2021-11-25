//
// Created by xyamix on 16.11.2021.
//

#include "LinearAlgebra.h"
#include <iostream>

using namespace std;

int Matrix::getSize() const {
    return this->size;
}

Matrix::Matrix(int n) {
    int **elements = (int **) malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++) {
        elements[i] = (int *) malloc(sizeof(int) * n);
    }
    this->elements = elements;
    this->size = n;
}

void Matrix::input() {
    int n = this->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int element;
            cin >> element;
            this->elements[i][j] = element;
        }
    }
}

void Matrix::print() {
    int n = this->size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << this->elements[i][j] << '\t';
        }
        cout << endl;
    }
}

void Matrix::setElements(int **elements) {
    this->elements = elements;
}

int ** Matrix::getElements() const {
    return this->elements;
}


Matrix operator+(Matrix &A, Matrix &B) {
    int size = A.getSize();
    Matrix C(size);
    int **A_elements = A.getElements();
    int **C_elements = C.getElements();
    int **B_elements = B.getElements();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C_elements[i][j] = A_elements[i][j] + B_elements[i][j];
        }
    }
    return C;
}

Matrix operator*(Matrix &A, Matrix &B) {
    int size = A.getSize();
    Matrix C(size);
    int **C_elements = C.getElements();
    int **B_elements = B.getElements();
    int **A_elements = A.getElements();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int element = 0;
            for (int k = 0; k < size; k++) {
                element += A_elements[i][k] * B_elements[k][j];
            }
            C_elements[i][j] = element;
        }
    }
    return C;
}

bool operator==(Matrix &A, Matrix &B) {
    int **B_elements = B.getElements();
    int **A_elements = A.getElements();
    for(int i = 0; i < A.getSize(); i++) {
        for(int j = 0; j < A.getSize(); j++){
            if(A_elements[i][j] != B_elements[i][j])
                return false;
        }
    }
    return true;
}

Matrix &Matrix::operator=(const Matrix &A) {
    elements = A.getElements();
    size = A.getSize();
    return *this;
}

Matrix::Matrix() {

}
