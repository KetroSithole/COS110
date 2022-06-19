#include "matrix.h"
#include <fstream>

#define F1 "test1.txt"
#define F2 "test2.txt"
#define F3 "test3.txt"
#define F4 "test4.txt"
#define F5 "test5.txt"
#define F6 "test6.txt"

using namespace std;

int main(){
    ifstream inFile1(F1);
    ifstream inFile2(F2);
    ifstream inFile3(F3);
    ifstream inFile4(F4);
    ifstream inFile5(F5);
    ifstream inFile6(F6);

    //================================================
    //Matrices used for calculations
    //================================================
    Matrix A(2,2);
    Matrix b(2,1);
    Matrix C(3,3);
    Matrix d(3,1);
    Matrix f(2,1);
    //================================================
        
    //================================================
    //Matrices used for error message testing
    //These Matrices will be left as "all zero"
    //Matrices as it is not required that they
    //contain any other values than zero
    //================================================
    Matrix Q(3,3);
    Matrix T(3,3);
    Matrix U(3,2);
    Matrix V(1,1);
    Matrix x(2,1);
    Matrix y(3,1);
    Matrix Z(4,4);
    //================================================


    inFile1 >> A;
    inFile2 >> C;
    inFile4 >> b;
    inFile3 >> d;
    inFile5 >> Q;
    inFile6 >> f;
    
    inFile1.close();
    inFile2.close();
    inFile3.close();
    inFile4.close();
    inFile5.close();

    cout << "_________________________________________________________________________\n";
    cout << "_________________________________________________________________________\n";
    cout << "The following are Matrices that will be used for (succesful) calcuations.\n\n";
    cout << "-------------------------------------\n";
    cout << "Matrix A is:\n" << A << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix b is:\n" << b << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix C is:\n" << C << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix d is:\n" << d << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix f is:\n" << f << endl;
    cout << "-------------------------------------\n";
    cout << "_________________________________________________________________________\n";
    
    cout << "_________________________________________________________________________\n";
    cout << "The followin are Matrices that will be used for testing error messages.\n\n";
    cout << "-------------------------------------\n";
    cout << "Matrix Q is:\n" << Q << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix U is:\n" << U << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix V is:\n" << V << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix x is:\n" << x << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix y is:\n" << y << endl;
    cout << "-------------------------------------\n";
    cout << "Matrix Z is:\n" << Z << endl;
    cout << "-------------------------------------\n";
    
    cout << "_________________________________________________________________________\n";
    ///////////////////////////////////////////////////////////////////////////////////// operator~()
    cout << "_________________________________________________________________________\n";
    cout << "Tests for: operator~():double\n\n";
    cout << "The Following will try to calculate the determinant of a 1x1 matrix, ~V\n";
    cout << "This should result in an error message as it is not 2x2 or 3x3. 0 should be returned\n";
    cout << "Take note that although it is not tested, the matrix should remain unchanged.\n\n";
    cout << "-------------------------------------\n";
    double returnedVal = ~V;
    cout << "Returned Value: " << returnedVal << endl;
    cout << "-------------------------------------\n";
   
    cout << "\nThe Following will try to calculate the determinant of a 4x4 matrix, ~V\n";
    cout << "This should result in an error message as it is not 2x2 or 3x3. 0 should be returned\n";
    cout << "Take note that although it is not tested, the matrix should remain unchanged.\n\n";
    
    cout << "-------------------------------------\n";
    returnedVal = ~Z;
    cout << "Returned Value: " << returnedVal << endl;
    cout << "-------------------------------------\n";
    cout << "\nThe Following will try to calculate the determinant of a 4x2 matrix, ~V\n";
    cout << "This should result in an error message as it is not 2x2 or 3x3. 0 should be returned\n";
    cout << "Take note that although it is not tested, the matrix should remain unchanged.\n\n";
    
    cout << "-------------------------------------\n";
    returnedVal = ~U;
    cout << "Returned Value: " << returnedVal << endl;
    cout << "-------------------------------------\n\n";
    
    cout << "The following calculates the determinant of a 2x2 matrix, ~A.\n";
    cout << "Remember that the determinant should also be stored in the denomitator private member.\n\n";
    cout << "-------------------------------------\n";
    returnedVal = ~A;
    cout << "Determinant of Matrix A is: " << returnedVal << endl;
    cout << "-------------------------------------\n";
    
    cout << "\nThe following calculates the determinant of a 3x3 matrix, ~C.\n";
    cout << "Remember that the determinant should also be stored in the denomitator private member.\n\n";
    cout << "-------------------------------------\n";
    returnedVal = ~C;
    cout << "Determinant of Matrix C is: " << returnedVal << endl;
    cout << "-------------------------------------\n";
    cout << "_________________________________________________________________________\n";
    ////////////////////////////////////////////////////////////////////////////////////////operator|=(Matrix&)
    cout << "_________________________________________________________________________\n";
    cout << "Tests for: operator|(Matrix&):double*\n\n";
    cout << "The following will try to calculate the linear determinants of a 3x2 matrix, U|y\n";
    cout << "This should result in an error message as the lhs matrix is not nxn, and NULL should be returned.\n";
    cout << "It is not tested, but both Matrices should remain unchanged.\n";

    cout << "\n-------------------------------------\n";
    double* doublePtr = U|y;
    cout << "Returned pointer is: " << doublePtr << endl;
    cout << "-------------------------------------\n";

    cout << "\nThe following will try to calculate the linear determinants of a 1x1 matrix, V|y\n";
    cout << "This should result in an error message as the lhs matrix is not 2x2 or 3x3, and NULL should be returned.\n";
    cout << "It is not tested, but both Matrices should remain unchanged.\n\n";
    
    cout << "-------------------------------------\n";
    doublePtr = V|y;
    cout << "Returned pointer is: " << doublePtr << endl;
    cout << "-------------------------------------\n";

    cout << "\nThe following will try to calculate the linear determinants of a 4x4 matrix, Z|y\n";
    cout << "This should result in an error message as the lhs matrix is not 2x2 or 3x3, and NULL should be returned.\n";
    cout << "It is not tested, but both Matrices should remain unchanged.\n\n";
    
    cout << "-------------------------------------\n";
    doublePtr = Z|y;
    cout << "Returned pointer is: " << doublePtr << endl;
    cout << "-------------------------------------\n";
    
    cout << "\nThe following will try to calculate the linear determinants of a 2x2 matrix, A|T\n";
    cout << "This should result in an error message as the rhs matrix is not nx1, and NULL should be returned.\n";
    cout << "It is not tested, but both Matrices should remain unchanged.\n\n";
    
    cout << "-------------------------------------\n";
    doublePtr = A|T;
    cout << "Returned pointer is: " << doublePtr << endl;
    cout << "-------------------------------------\n";
    
    cout << "\nThe following will try to calculate the linear determinants of a 2x2 matrix, A|d\n";
    cout << "Although the dimensions of the lhs are correct, it should still result in an error message\nas, the rhs matrix's row count doesn't match the left, and NULL should be returned.\n";
    cout << "It is not tested, but both Matrices should remain unchanged.\n\n";

    cout << "-------------------------------------\n";
    doublePtr = A|d;
    cout << "Returned pointer is: " << doublePtr << endl;
    cout << "-------------------------------------\n";

    cout << "\nThe following will determine the linear determinants of a 2x2 Matrix, A|f.\n";
    cout << "These determinants should also be stored in the respective private member.\n\n";
    
    cout << "-------------------------------------\n";
    doublePtr = A|f;
    for(int count = 0; count < A.getRows(); count++){
        cout << "Linear Determinant " << count << " is: " << doublePtr[count] << endl;
    }
    cout << "-------------------------------------\n";
    
    cout << "\nThe following will determine the linear determinants of a 3x3 Matrix, C|d.\n";
    cout << "These determinants should also be stored in the respective private member.\n\n";
    
    cout << "-------------------------------------\n";
    doublePtr = C|d;
    for(int count = 0; count < C.getRows(); count++){
        cout << "Linear Determinant " << count << " is: " << doublePtr[count] << endl;
    }
    cout << "-------------------------------------\n";
    cout << "_________________________________________________________________________\n";
   ////////////////////////////////////////////////////////////////////////////////////////operator|=(Matrix)
    cout << "_________________________________________________________________________\n";
    cout << "Tests for: operator|=(Matrix&):Matrix\n\n";

    cout << "The following will try to set the new Matrix s equal to the linear solutions of a 3x2 matrix, s = U|=y\n";
    cout << "This should result in an error message as the lhs matrix is not 3x3 or 2x2, and the rhs matrix should be returned.\n";
    cout << "s shpuld now be equal to y. It is not tested, but both Matrices should remain unchanged.\n";
    
    cout << "\n-------------------------------------\n";
    Matrix s = U|=y;
    cout << "Resulting Matrix s is:\n" << s;
    cout << "-------------------------------------\n";
    
    cout << "\nThe following will try to set s equal to the solutions of a 4x4 matrix, s = Z|=d.\nThis should result in an error message as it is not 2x2 or 3x3.\n";
    cout << "The rhs side matrix should be returned and s should therefore now be equal to d.\nIt is not tested but noth Z and d should remain unchanched.\n";
    
    cout << "\n-------------------------------------\n";
    s = Z|=d;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";
    
    cout << "\nThe following will try to set s equal to the solutions of a 1x1 matrix, s = V|=b.\nThis should result in an error message as it is not 2x2 or 3x3.\n";
    cout << "The rhs side matrix should be returned and s should therefore now be equal to b.\nIt is not tested but noth V and b should remain unchanched.\n";

    cout << "\n-------------------------------------\n";
    s = V|=b;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";

    cout << "\nThe following will attempt to set s equal to the linear solutions of a 3x3 matrix, s = C|b.\n";
    cout << "While the lhs matrix is of the right size, it will result in an error\nmessage as the rhs matrix does not have the correct amount of rows.\n";
    cout << "It is not tested, but C and b should remain unchanged, and s should now be equal to b.\n";

    cout << "\n-------------------------------------\n";
    s = C|=b;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";

    cout << "\nThe following will attempt to set s equal to the linear solutions of a 3x3 matrix, s = C|=C.\n";
    cout << "While the lhs matrix is of the right size, it will result in an error\nmessage as the rhs matrix does not have the correct dimensions.\n";
    cout << "It is not tested, but C should remain unchanged, and s should now be equal to C.\n";
    
    cout << "\n-------------------------------------\n";
    s = C|=C;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";

    cout << "\nThis will attempt set s equal to linear solutions of of a 3x3 matrix, s = Q|=d.\n";
    cout << "While both matrices has the correct dimensions, this will result in an error message\nas the determinant of Q is 0.\n";
    cout << "Q and d should remain unchanged, and s should now be equal to d.\n";
    
    cout << "\n-------------------------------------\n";
    s = Q|=d;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";

    cout << "\nThis will determine the linear solutions of a 2x2 matrix and store the results in matrix s. s = A|=b\nIt is not tested b should remain unchanged, and the solutions should be stored in linearSolutions of A.\n";

    cout << "\n-------------------------------------\n";
    s = A|=b;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";

    cout << "\nLastly, the linear solutions of a 3x3 matrix will be calculated and stored in s. s = C|=d\n";
    cout << "It is not tested but d should remain unchanged and the solutions should be stored in linearSolutions of C.\n";
    
    cout << "\n-------------------------------------\n";
    s = C|=d;
    cout << "Matrix s is now:\n" << s;
    cout << "-------------------------------------\n";
    cout << "end of testing\n";
    return 0;
}