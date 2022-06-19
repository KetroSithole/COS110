#include "matrix.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream infile("input.txt");
    ifstream infile2("inputb.txt");
    Matrix a(2, 2);
    Matrix b(2, 1);
    cout << a << endl;
    cout << b << endl;

    infile >> a;
    infile2 >> b;
    cout << a << endl;
    cout << b << endl;
    infile.close();
    infile2.close();

    return 0;
}

/* Output
0         0
0         0

0
0

12        3
2        -3

15
13
 */