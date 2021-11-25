//
// Created by xyamix on 16.11.2021.
//

#ifndef GROUPTHEORY_LINEARALGEBRA_H
#define GROUPTHEORY_LINEARALGEBRA_H

class Matrix {
private:
    int **elements;
    int size;
public:
    Matrix(int n);
    Matrix();
    friend Matrix operator*(Matrix &A, Matrix &B);
    friend Matrix operator+(Matrix &A, Matrix &B);
    Matrix& operator=(const Matrix &A);
    friend bool operator==(Matrix &A, Matrix &B);
    void input();
    void print();
    void setElements(int **elements);
    int ** getElements() const;
    int getSize() const;
};


#endif //GROUPTHEORY_LINEARALGEBRA_H
