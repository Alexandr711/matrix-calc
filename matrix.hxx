#ifndef _MATRIX_HXX_
#define _MATRIX_HXX_

#include <iostream>
#include <iomanip>

class Matrix{
    private:
    int str;
    int cols;
    float **matrix;

    public:
    Matrix();
    Matrix(int, int);
    Matrix(const Matrix&);
    ~Matrix();
    void enterMatrix();
    void outputMatrix();
    Matrix operator+(const Matrix&);
    Matrix operator-(const Matrix&);
    Matrix operator=(const Matrix&);
    Matrix mulNum(float);
    Matrix transposition();
};

#endif