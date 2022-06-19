#include "matrix.h"
#include <fstream>

#define F1 "test1.txt"
#define F2 "test2.txt"
#define F3 "test3.txt"

using namespace std;

int main(){
   ifstream inFile1(F1);
   ifstream inFile2(F2);
   Matrix A(3, 4);
   Matrix E(3, 3);
   cout << "___________________________________________________________\n";
   cout << "Reading in Matrix A...\n";
   inFile1 >> A;
   cout << "Initial Matrix A is:\n";
   cout << A;
   cout << "\nReading in Matrix E...\n";
   inFile2 >> E;
   cout << "Initial Matrix E is:\n" << E;
   inFile1.close();
   inFile2.close();
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*(double)
   cout << "___________________________________________________________\n";
   cout << "Multiplying A by 2, using A = A*2...\n";
   A = A*2;
   cout << "A is now:\n";
   cout << A;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*(double)
   cout << "___________________________________________________________\n";
   cout << "Creating a new matrix, Matrix B, B = A*3.5...\n";
   Matrix B = A*3.4;
   cout << "Both A and B will be printed, however, A\nshould have remained unchanged.\n";
   cout << "Matrix A is:\n" << A;
   cout << "\nMatrix B is:\n" << B;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*(double, Matrix)
   cout << "___________________________________________________________\n";
   cout << "Setting B equal to 3.7*A, B = 3.7*A\n";
   B = 3.7*A;
   cout << "A should remain unchanged.\n";
   cout << "Matrix A is:\n" << A;
   cout << "\nMatrix B is:\n" << B;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*=(double)
   cout << "___________________________________________________________\n";
   cout << "Multiplying B by 0.7 using *=, B *= 0.7\n";
   B *= 0.7;
   cout << "B is now;\n" << B;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator/(double)
   cout << "___________________________________________________________\n";
   cout << "Attempt to divide B by zero, B = B/0.\nShould return an error message and B should remain unchanged.\n\n";
   B = B/0;
   cout << "Matrix B is:\n";
   cout << B << endl;
   cout << "Creating a new Matrix C that is equal to B divided by 4.2. B should remain unchanged.\n";
   Matrix C = B/4.2;
   cout << "Matrix B is:\n" << B << endl;
   cout << "Matrix C is:\n" << C;
   cout << "\nThis will again attempt to divide by zero,\nB = A/0, in this instance B should now be equal to A, and A  unchanged\n\n";
   B = A/0;
   cout << "Matrix A is:\n" << A;
   cout << "\nMatrix B is:\n" << B;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator+(Matrix)
   cout << "___________________________________________________________\n";
   cout << "A new matrix, D will now be set equal to A+B+C, D = A + B + C.\nA, B and C should remain unchanged\n";
   Matrix D = A + B + C;
   cout << "Matrix A is:\n" << A;
   cout << "\nMatrix B is:\n" << B;
   cout << "\nMatrix C is:\n" << C;
   cout << "\nMatrix D is:\n" << D;
   cout << "\nThe following will try to set C = E+A,\nthis should result in an error message since\nthey do not have the same dimensions.\n";
   cout << "Both A and E should remain unchanged, and C should now be equal to E.\n\n";
   C = E+A;
   cout << "Matrix A is:\n" << A;
   cout << "\nMatrix E is:\n" << E;
   cout << "\nMatrix C is:\n" << C;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator+=(Matrix)
   cout << "___________________________________________________________\n";
   cout << "This portion of code will add E to C using C += E.\n";
   C += E;
   cout << "C is now:\n" << C;
   cout << "\n The following will try to add C to A, A += C\nThis should result in an error message as their dimensions do not match.\n";
   cout << "A should remain unchanged.\n\n";
   A += C;
   cout << "A is:\n" << A;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator-(Matrix)
   cout << "___________________________________________________________\n";
   cout << "The following will set B = B - A/3.\nMatrix A should remain the same.\n";
   B = B - A/3;
   cout << "\nMatrix A is:\n" << A;
   cout << "\nMatrix B is:\n" << B;
   cout << "\nThe following will attempt to subtract A from E and store it in D, D = E - A,\nthis should result in an error message as the dimensions are not the same.\n";
   cout << "Furthermore, D should now be equal to E, and E\nand A should have remained unchanged.\n\n";
   D = E - A;
   cout << "Matrix A is:\n" << A << endl;
   cout << "Matrix E is:\n" << E << endl;
   cout << "Matrix D is now:\n" << D;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator-=(Matrix)
   cout << "___________________________________________________________\n";
   cout << "The following will subtract B from A, A -= B, B should remain unchanged.\n";
   A -= B;
   cout << "\nMatrix A is:\n" << A << endl;
   cout << "Matrix B is:\n" << B << endl;
   cout << "The following will attempt to subtract C from A, A -= C,\nthis should result in an error message since the dimension do not match\n";
   cout << "Furthermore, both matrices should remain unaltered.\n\n";
   A -= C;
   cout << "Matrix A is:\n" << A << endl;
   cout << "Matrix B is:\n" << B;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*(Matrix)
   cout << "___________________________________________________________\n";
   cout << "The following will set D = ExA, D = E*A.\nA and E should remain unchanged.\n";
   D = E*A;
   cout << "\nMatrix E is:\n" << E << endl;
   cout << "Matrix A is:\n" << A << endl;
   cout << "Matrix D is now:\n" << D << endl;
   cout << "The following will atempt to multiple A with D and set it equal to D, D = A*D.\n";
   cout << "This should result in an error message since the dimensions are incorrect.\n";
   cout << "Furthermore, A should remain unchanged and D should now be equal to A.\n\n";
   D = A*D;
   cout << "A is:\n" << A << endl;
   cout << "D is now:\n" << D;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator*=(Matrix)
   cout << "___________________________________________________________\n";
   cout << "The following will set E equal to E times A using E *= A.\n";
   cout << "A should remain unchanged.\n";
   E *= A;
   cout << "\nE is now:\n" << E << endl;
   cout << "A is:\n" << A << endl;
   cout << "The following will try to set A equal to A times E using, A *= E\n";
   cout << "This should result in an error message as the dimensions are not compatible\nand both matrices should remain unchanged.\n\n";
   A *= E;
   cout << "\nA is:\n" << A << endl;
   cout << "E is:\n" << E << endl;
   cout << "___________________________________________________________\n";
   cout << "___________________________________________________________\n";
   cout << "A new square Matrix will now be read in, Matrix F.\n\n";
   Matrix F(3, 3);
   ifstream inFile3(F3);
   inFile3 >> F;
   cout << "Matrix F is:\n" << F;
   
///////////////////////////////////////////////////////////////////////////////////  operator^(Matrix)
   cout << "___________________________________________________________\n";
   cout << "___________________________________________________________\n";
   cout << "The following will set A equal to F raised to the third power.\n";
   cout << "A = F^3, F should remain unchanged.\n";
   A = F^3;
   cout << "\nA is now:\n" << A << endl;
   cout << "F is:\n" << F << endl;
   cout << "The following will set A equal to C raised to the zeroth power, A = C^0\nA should now be equal to the identity Matrix, and C should remain unchanged.\n\n";
   A = C^0;
   cout << "A is now:\n" << A << endl;
   cout << "C is:\n" << C << endl;
   cout << "The following statement will attemp to set B equal to E raised to the second power, B = E^2.\n";
   cout << "This should result in an error message as E is not a square matrix, E should remain the same, and B should now be equal to E.\n\n";
   B = E^2;
   cout << "E is:\n" << E << endl;
   cout << "B is now:\n" << B << endl;
   cout << "The following will attempt to set B equal to A raised to a negative power, B = A^-1\n";
   cout << "This should result in an error message as the code does not support negative powers.\n";
   cout << "A should remain unchanged and B should now be equal to A.\n\n";
   B = A^-1;
   cout << "B is now:\n" << B <<  endl;
   cout << "A is:\n" << A;
   cout << "___________________________________________________________\n";
///////////////////////////////////////////////////////////////////////////////////  operator^(Matrix)
   cout << "___________________________________________________________\n";
   cout << "The following will Attempt to raise A to negative power,A ^= -1.\nthis should result in an error message, and A should remain unchanged\n\n";
   A ^= -1;
   cout << "A is:\n" << A << endl;
   cout << "The following will attempt tp raise E to the second power, E ^= 2.\nThis should result in an error message as E is not sqaure, and E should remain unchanged.\n\n";
   E ^= 2;
   cout << "E is:\n" << E << endl;
   cout << "The following will raise C to the second power.\n\n";
   C ^= 2;
   cout << "C is now:\n" << C << endl;
   cout << "Lastly, C will now be raised to the zeroth power.\n";
   C ^= 0;
   cout << "\nC is now:\n" << C;
   cout << "___________________________________________________________\n";
   cout << "___________________________________________________________\n";
   cout << "end of test program\n";
   return 0;
}