#include "matrix.h"
#include <fstream>
#include <iomanip>




//Constructor.
Matrix::Matrix(unsigned r, unsigned c)
{
    rows = r;
    cols = c;

    matrix = new double *[rows];
    for (int xIndex=0;  xIndex<rows;    xIndex++)
    {
        matrix[xIndex] = new double [cols];
        for (int yIndex=0;    yIndex<cols;     yIndex++)
        {
            matrix[xIndex][yIndex] = 0.0;
        }
    }
}




//Copy constructor.
Matrix::Matrix(const Matrix &rhs)
{
    rows = rhs.rows;
    cols = rhs.cols;

    matrix = new double *[rows];
    for (int xIndex=0;  xIndex<rows;    xIndex++)
    {
        matrix[xIndex] = new double [cols];
        for (int yIndex=0;  yIndex<cols;    yIndex++)
        {
            matrix[xIndex][yIndex] = rhs.matrix[xIndex][yIndex];
        }
    }
}



//Destructor.
Matrix::~Matrix()
{
    for (int index=0;   index<rows;   index++)
    {
        delete [] matrix[index];
    }
    delete [] matrix;
}




const Matrix &Matrix::operator=(const Matrix &rhs)
{
    if (this != &rhs)
    {
        //Deallocate the memory first.
        for (int xIndex=0;  xIndex<this->getRows();   xIndex++)
        {
            delete [] matrix[xIndex];
        }
        delete [] matrix;

        rows = rhs.rows;
        cols = rhs.cols;

        //Assign new memory
        matrix = new double *[rows];
        for (int xIndex=0;  xIndex<rows;    xIndex++)
        {
            matrix[xIndex] = new double [cols];
            for (int yIndex=0;  yIndex<cols;    yIndex++)
            {
                matrix[xIndex][yIndex] = rhs.matrix[xIndex][yIndex];
            }
        }
    }
    return *this;
}




//Accessors
double &Matrix::operator()(const unsigned r, const unsigned c)
{
    return matrix[r][c];
}




const double &Matrix::operator()(const unsigned r, const unsigned c) const
{
    return matrix[r][c];
}




Matrix Matrix::operator[](const unsigned r) const
{
    unsigned columns = this->getCols();

    Matrix temp(1, columns);

    for (int yIndex=0;  yIndex<columns; yIndex++)
    {
        temp.matrix[0][yIndex] = matrix[r][yIndex];
    }
    return temp;
}


//Getters.
unsigned Matrix::getRows() const
{
    return rows;
}




unsigned Matrix::getCols() const
{
    return cols;
}




//Insertion overload
ostream &operator<<(ostream &strm, const Matrix &mat)
{
    for (int xIndex=0;   xIndex<mat.getRows();  xIndex++)
    {
        for (int yIndex=0;    yIndex<mat.getCols();  yIndex++)
        {
            strm << setw(10) << setprecision(3);
            strm << mat.matrix[xIndex][yIndex];
        }
        strm << endl;
    }
    return strm;
}




//Extraction overload
istream &operator>>(istream &strm, Matrix &mat)
{
    for (int xIndex=0;  xIndex<mat.getRows();   xIndex++)
    {
        for (int yIndex=0;  yIndex<mat.getCols();   yIndex++)
        {
            strm >> mat.matrix[xIndex][yIndex];
        }
    }
    return strm;
}