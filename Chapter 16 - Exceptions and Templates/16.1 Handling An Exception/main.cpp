//This program demonstrates an exception being thrown and caught.
#include <iostream>
#include <string>

using namespace std;

//Function prototype
double divide (int, int);

int main()
{
    int num1, num2;             //To hold two numbers
    double quotient;            //To hold the quotient of the numbers

    //Get the two numbers.
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    //Divide num1 by num2 and catch any potential exceptions;
    try{
        quotient = divide(num1, num2);
        cout << "The quotient is " << quotient << endl;
    }
    catch(string exceptionString){
        std::cout<< exceptionString;
    }

    cout << "End of the program.\n";
    return 0;    
}

/*
*************************************************************************
    The divide function divides the numerator by the denominator.       *
    If the denominator us zero, the function throws ann exception.      *
*************************************************************************
*/

double divide (int numerator, int denominator){
    if (denominator == 0){
        string exceptionString = "ERROR: Cannot divide by zero.\n";
        throw exceptionString;
    }
    return static_cast<double>(numerator)/denominator;
}