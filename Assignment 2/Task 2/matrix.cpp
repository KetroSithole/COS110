#include "matrix.h"
#include <fstream>
#include <iomanip>


//Constructor.
Matrix::Matrix(unsigned r, unsigned c){
    rows = r;
    cols = c;

    matrix = new double *[rows];
    for (int xIndex=0;  xIndex<rows;    xIndex++){
        matrix[xIndex] = new double [cols];
        for (int yIndex=0;    yIndex<cols;     yIndex++){
            matrix[xIndex][yIndex] = 0.0;
        }
    }
}


//Copy constructor.
Matrix::Matrix(const Matrix &rhs){
    rows = rhs.rows;
    cols = rhs.cols;

    matrix = new double *[rows];
    for (int xIndex=0;  xIndex<rows;    xIndex++){
        matrix[xIndex] = new double [cols];
        for (int yIndex=0;  yIndex<cols;    yIndex++){
            matrix[xIndex][yIndex] = rhs.matrix[xIndex][yIndex];
        }
    }
}


//Destructor.
Matrix::~Matrix(){
    for (int index=0;   index<rows;   index++){
        delete [] matrix[index];
    }
    delete [] matrix;
}


//Overload assignment operator.
const Matrix &Matrix::operator=(const Matrix &rhs){
    if (this != &rhs){
        //Deallocate the memory first.
        for (int xIndex=0;  xIndex<this->getRows();   xIndex++){
            delete [] matrix[xIndex];
        }
        delete [] matrix;

        rows = rhs.rows;
        cols = rhs.cols;

        //Assign new memory
        matrix = new double *[rows];
        for (int xIndex=0;  xIndex<rows;    xIndex++){
            matrix[xIndex] = new double [cols];
            for (int yIndex=0;  yIndex<cols;    yIndex++){
                matrix[xIndex][yIndex] = rhs.matrix[xIndex][yIndex];
            }
        }
    }
    return *this;
}


// Matrix mathematical operations
Matrix Matrix::operator+(const Matrix &rhs){
    if (this->getRows() == rhs.getRows() && this->getCols() == rhs.getCols()){
        Matrix temp (this->getRows(), this->getCols());

        for (int xIndex=0;  xIndex<this->getRows();    xIndex++){
            for (int yIndex=0;  yIndex<this->getCols();    yIndex++){
                temp.matrix[xIndex][yIndex] = matrix[xIndex][yIndex] + rhs.matrix[xIndex][yIndex];
            }
        }
        return temp;
    }
    else{
        cout << "Error: adding matrices of different dimensionality" << endl;
    }
    return *this;
}


Matrix &Matrix::operator+=(const Matrix &rhs){
    if (this->getRows() == rhs.getRows() && this->getCols() == rhs.getCols()){
        for (int xIndex=0;  xIndex<this->getRows();    xIndex++){
            for (int yIndex=0;  yIndex<this->getCols();    yIndex++){
                matrix[xIndex][yIndex] += rhs.matrix[xIndex][yIndex];
            }
        }
        return *this;
    }
    else{
        cout << "Error: adding matrices of different dimensionality" << endl;
    }
    return *this;
}


Matrix Matrix::operator-(const Matrix &rhs){
    if (this->getRows() == rhs.getRows() && this->getCols() == rhs.getCols()){
        Matrix temp (this->getRows(), this->getCols());

        for (int xIndex=0;  xIndex<this->getRows();    xIndex++){
            for (int yIndex=0;  yIndex<this->getCols();    yIndex++){
                temp.matrix[xIndex][yIndex] = matrix[xIndex][yIndex] - rhs.matrix[xIndex][yIndex];
            }
        }
        return temp;
    }
    else{
        cout << "Error: subtracting matrices of different dimensionality" << endl;
    }
    return *this;
}


Matrix &Matrix::operator-=(const Matrix &rhs){
    if (this->getRows() == rhs.getRows() && this->getCols() == rhs.getCols()){
        for (int xIndex=0;  xIndex<this->getRows();    xIndex++){
            for (int yIndex=0;  yIndex<this->getCols();    yIndex++){
                matrix[xIndex][yIndex] -= rhs.matrix[xIndex][yIndex];
            }
        }
        return *this;
    }
    else{
        cout << "Error: subtracting matrices of different dimensionality" << endl;
    }
    return *this;
}


Matrix Matrix::operator*(const Matrix &rhs){
    if (this->getCols() == rhs.getRows()){
        Matrix temp (this->getRows(), rhs.getCols());
        
        for(int xIndex=0;    xIndex<this->getRows();      xIndex++){
            for(int yIndex=0;    yIndex<rhs.getCols();      yIndex++){
                temp.matrix[xIndex][yIndex] = 0.0;
                for(int zIndex= 0;      zIndex<this->getCols();     zIndex++){
                    temp.matrix[xIndex][yIndex] += matrix[xIndex][zIndex] * rhs.matrix[zIndex][yIndex];
                }
            }
        }
        return temp;
    }
    else{
        cout << "Error: invalid matrix multiplication" << endl;
    }
    return *this;
}


Matrix &Matrix::operator*=(const Matrix &rhs){
    if (this->getCols() == rhs.getRows()){
        Matrix temp (this->getRows(), rhs.getCols());
        
        for(int xIndex=0;    xIndex<this->getRows();      xIndex++){
            for(int yIndex=0;    yIndex<rhs.getCols();    yIndex++){
                for(int zIndex= 0;      zIndex<this->getCols();     zIndex++){
                    temp.matrix[xIndex][yIndex] += matrix[xIndex][zIndex] * rhs.matrix[zIndex][yIndex];
                }
            }
        }
        
        for (int i=0;   i<this->getRows();  i++){
            delete [] this->matrix[i];
        }
        delete [] this->matrix;

        this->matrix = new double *[this->getRows()];
        for(int xIndex=0;    xIndex<this->getRows();      xIndex++){
            this->matrix[xIndex] = new double [rhs.getCols()];
            for(int yIndex=0;    yIndex<rhs.getCols();    yIndex++){
                this->matrix[xIndex][yIndex] = temp.matrix[xIndex][yIndex];
            }
        }
        return *this;
    }
    else{
        cout << "Error: invalid matrix multiplication" << endl;
    }
    return *this;
}


Matrix Matrix::operator^(int pow){
    if  (pow < 0){
        cout << "Error: negative power is not supported" << endl;
        return *this;
    }

    else if (this->getRows() != this->getCols()){
        cout << "Error: non-square matrix provided" << endl;
        return *this;
    }

    else if (this->getRows() == this->getCols()){
        if (pow > 0){
            Matrix temp (this->getRows(),   this->getCols());
            Matrix matrix1 (this->getRows(),   this->getCols());
            Matrix matrix2 (this->getRows(),   this->getCols());

            for (int xIndex=0;      xIndex<this->getRows();     xIndex++){
                for (int yIndex=0;      yIndex<this->getCols();     yIndex++){
                    matrix1.matrix[xIndex][yIndex] = this->matrix[xIndex][yIndex];
                    matrix2.matrix[xIndex][yIndex] = this->matrix[xIndex][yIndex];
                }
            }

            for (int index=0;   index<pow-1;    index++){
                for (int xIndex=0;      xIndex<this->getRows();     xIndex++){
                    for (int yIndex=0;      yIndex<this->getCols();     yIndex++){
                        temp.matrix[xIndex][yIndex] = 0.0;
                        for (int zIndex=0;      zIndex<this->getRows();     zIndex++){
                            temp.matrix[xIndex][yIndex] += matrix1.matrix[xIndex][zIndex] * matrix2.matrix[zIndex][yIndex];
                        }
                    }
                }

                for (int xIndex=0;      xIndex<this->getRows();     xIndex++){
                    for (int yIndex=0;      yIndex<this->getCols();     yIndex++){
                        matrix1.matrix[xIndex][yIndex] = temp.matrix[xIndex][yIndex];
                    }
                }
            }
            return matrix1;
        }

        else if (pow == 0){
            Matrix mat (this->getRows(), this->getCols());

            for (int xIndex=0;  xIndex<this->getRows();     xIndex++){
                for (int yIndex=0;  yIndex<this->getCols();     yIndex++){
                    if (xIndex == yIndex){
                        mat.matrix[xIndex][yIndex] = 1.0;
                    }
                    else{
                        mat.matrix[xIndex][yIndex] = 0.0;
                    }
                }
            }
            return mat;
        }
    }
    return *this;
}


Matrix &Matrix::operator^=(int pow){
    if (pow < 0){
        cout << "Error: negative power is not supported" << endl;
    }

    else if (this->getRows() != this->getCols()){
        cout << "Error: non-square matrix provided" << endl;
    }

    else if (this->getRows() == this->getCols()){
        if (pow == 0){
            for (int xIndex=0;      xIndex<this->getRows();     xIndex++){
                for (int yIndex=0;      yIndex<this->getCols();     yIndex++){
                    if (xIndex == yIndex){
                        this->matrix[xIndex][yIndex] = 1.0;
                    }
                    else{
                        this->matrix[xIndex][yIndex] = 0.0;
                    }
                }
            }
            return *this;
        }

        else if (pow > 0){
            Matrix temp (this->getRows(),   this->getCols());
            Matrix arr1 (this->getRows(),   this->getCols());
            Matrix arr2 (this->getRows(),   this->getCols());

            for (int xIndex=0;      xIndex<this->getRows();     xIndex++){
                for (int yIndex=0;      yIndex<this->getCols();     yIndex++){
                    arr1.matrix[xIndex][yIndex] = this->matrix[xIndex][yIndex];
                    arr2.matrix[xIndex][yIndex] = this->matrix[xIndex][yIndex];
                }
            }

            for(int index=0;    index<pow-1;        index++){
                for(int xIndex=0;      xIndex<this->getRows();  xIndex++){
                    for(int yIndex=0;       yIndex<this->getCols();       yIndex++){
                        temp.matrix[xIndex][yIndex] = 0;   
                        for(int zIndex=0;       zIndex<this->getRows();      zIndex++){
                            temp.matrix[xIndex][yIndex] += arr1.matrix[xIndex][zIndex] * arr2.matrix[zIndex][yIndex];
                        }
                    }
                }

                for(int xIndex=0;       xIndex<this->getRows();         xIndex++){
                    for(int yIndex=0;       yIndex<this->getCols();         yIndex++){   
                        this->matrix[xIndex][yIndex]=temp.matrix[xIndex][yIndex];
                    }
                }
            }
        }
        return *this;
    }
    return *this; 
}


// Matrix/scalar operations
Matrix Matrix::operator*(const double &rhs){
    Matrix temp (this->getRows(), this->getCols());

    for (int xIndex=0;  xIndex<this->getRows();     xIndex++){
        for (int yIndex=0;  yIndex<this->getCols();     yIndex++){
            temp.matrix[xIndex][yIndex] = this->matrix[xIndex][yIndex] * rhs;
        }
    }
    return temp;
}


Matrix &Matrix::operator*=(const double &rhs){
    for (int xIndex=0;  xIndex<this->getRows();     xIndex++){
        for (int yIndex=0;  yIndex<this->getCols();     yIndex++){
            matrix[xIndex][yIndex] *= rhs;
        }
    }
    return *this;
}


Matrix Matrix::operator/(const double &rhs){
    Matrix temp (this->getRows(), this->getCols());
    if (rhs > 0 || rhs < 0){
        for (int xIndex=0;  xIndex<this->getRows();     xIndex++){
            for (int yIndex=0;  yIndex<this->getCols();     yIndex++){
                temp.matrix[xIndex][yIndex] = matrix[xIndex][yIndex] / rhs;
            }
        }
    }
    else if (rhs == 0){
        cout << "Error: division by zero" << endl;
        return *this;
    }
    return temp;
}


Matrix operator*(const double &lhs, const Matrix &rhs){
    Matrix temp (rhs.getRows(), rhs.getCols());
    for (int xIndex=0;  xIndex<rhs.getRows();     xIndex++){
        for (int yIndex=0;  yIndex<rhs.getCols();     yIndex++){
            temp.matrix[xIndex][yIndex] = lhs * rhs.matrix[xIndex][yIndex];
        }
    }
    return temp;
}


//Accessors
double &Matrix::operator()(const unsigned r, const unsigned c){
    return matrix[r][c];
}


const double &Matrix::operator()(const unsigned r, const unsigned c) const{
    return matrix[r][c];
}


Matrix Matrix::operator[](const unsigned r) const{
    unsigned columns = this->getCols();

    Matrix temp(1, columns);

    for (int yIndex=0;  yIndex<columns; yIndex++){
        temp.matrix[0][yIndex] = matrix[r][yIndex];
    }
    return temp;
}


//Getters.
unsigned Matrix::getRows() const{
    return rows;
}


unsigned Matrix::getCols() const{
    return cols;
}


//Insertion overload
ostream &operator<<(ostream &strm, const Matrix &mat){
    for (int xIndex=0;   xIndex<mat.getRows();  xIndex++){
        for (int yIndex=0;    yIndex<mat.getCols();  yIndex++){
            strm << setw(10) << setprecision(3);
            strm << mat.matrix[xIndex][yIndex];
        }
        strm << endl;
    }
    return strm;
}


//Extraction overload
istream &operator>>(istream &strm, Matrix &mat){
    for (int xIndex=0;  xIndex<mat.getRows();   xIndex++){
        for (int yIndex=0;  yIndex<mat.getCols();   yIndex++){
            strm >> mat.matrix[xIndex][yIndex];
        }
    }
    return strm;
}