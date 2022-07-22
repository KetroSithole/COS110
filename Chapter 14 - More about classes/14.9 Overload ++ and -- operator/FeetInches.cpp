//Implementation file for the FeetInches class
#include <cstdlib>
#include "FeetInches.h"

/*
********************************************************************************************************************************************
	Definition of member functions simplify.                                                                                               *
	This function checks for values in the inches member greater than twelve or less than zero.                                            *
	If such value is found, the numbers in feet and inches are adjusted to conform to a standard feet & inches expression.                 *
	For example, 3 feet 14 inches would be adjusted to 4 feet 2 inches and 5 feet -2 inches would be adjusted to 4 feet and 10 inches.     *
********************************************************************************************************************************************
*/

void FeetInches::simplify(){
	if (inches >= 12){
		feet += (inches / 12);
		inches = inches % 12;
	}
	else if (inches < 0){
		feet -= ( (abs(inches) / 12) + 1);
		inches = 12 - ( abs(inches) % 12);
	}
}


/*
**************************************
	Overload binary + operator
**************************************
*/

FeetInches FeetInches::operator+ (const FeetInches &right){
	FeetInches temp;

	temp.inches = inches + right.inches;
	temp.feet = feet + right.feet;
	temp.simplify();
	return temp;
}


/*
**************************************
	Overload binary - operator
**************************************
*/

FeetInches FeetInches::operator- (const FeetInches &right){
	FeetInches temp;

	temp.inches = inches - right.inches;
	temp.feet = feet - right.feet;
	temp.simplify();
	return temp;
}


/*
**************************************
	Overload binary  pre ++ operator
**************************************
*/

FeetInches FeetInches::operator++ (){
	++inches;
	simplify();
	return *this;
}


/*
**************************************
	Overload binary  post ++ operator
**************************************
*/

FeetInches FeetInches::operator++ (int){
	FeetInches temp (feet, inches);
	++inches;
	simplify();
	return *this;
}
