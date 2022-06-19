#ifndef ASSIGNMENT_2_MATRIX_H
#define ASSIGNMENT_2_MATRIX_H

#include <iostream>

using namespace std;

class Matrix
{
    friend ostream &operator<<(ostream &, const Matrix &);
    friend istream &operator>>(istream &, Matrix &);
    friend Matrix operator*(const double &, const Matrix &);

    private:

        void setMatrix(double **m);

        double **matrix;
        double *linearDeterminants;
        double *linearSolutions;
        double denominator;
        unsigned rows;
        unsigned cols;

    public:

        Matrix(unsigned r, unsigned c);
        Matrix(const Matrix &rhs);
        ~Matrix();
        const Matrix &operator=(const Matrix &rhs);

        // Matrix mathematical operations
        Matrix operator+(const Matrix &rhs);
        Matrix &operator+=(const Matrix &rhs);
        Matrix operator-(const Matrix &rhs);
        Matrix &operator-=(const Matrix &rhs);
        Matrix operator*(const Matrix &rhs);
        Matrix &operator*=(const Matrix &rhs);
        Matrix operator^(int pow);
        Matrix &operator^=(int pow);

        // Matrix/scalar operations
        Matrix operator*(const double &rhs);
        Matrix &operator*=(const double &rhs);
        Matrix operator/(const double &rhs);

        // Access the individual elements
        double &operator()(const unsigned r, const unsigned c);
        const double &operator()(const unsigned r, const unsigned c) const;
        Matrix operator[](const unsigned r) const;

        // Getters and setters:
        unsigned getRows() const;
        unsigned getCols() const;

        // Linear equations:
        double operator~(); //
        double *operator|(Matrix &rhs);
        Matrix operator|=(Matrix &rhs);
};
#endif //ASSIGNMENT_2_MATRIX_H
