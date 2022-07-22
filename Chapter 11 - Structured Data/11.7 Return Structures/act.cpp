/*
	This program uses a function to return a structure. 
	This is a modification of program 11.2
*/
#include <iostream>
#include <iomanip>
#include <cmath>				//For the pow function

using namespace std;

//Constant for pi.
const double PI = 3.141592654;

//Structure Declaration
struct Circle
{
	double radius;			//A circle's radius
	double diameter;		//A circle's diameter
	double area;			//A circle's area.
};


//Function prototype
Circle getInfo();


//**********************************************************************************************
/*
	Definition of function getInfo.
	This function uses a local variable, tempCircle, which is a circle structure.
	The user enters the diameter of the circle, which is stored in tempCircle.diameter.
	The function then calculates the radius, which is stored in tempCircle.radius.
	tempCircle is then returned from the function
*/
//**********************************************************************************************


Circle getInfo()
{
	Circle tempCircle;				//Temporary structure variable

	//Store circle data in the temporary variable.
	cout << "Enter the diameter of the circle: ";
	cin >> tempCircle.diameter;
	tempCircle.radius = tempCircle.diameter / 2.0;

	//Return the temporary variable.
	return tempCircle;
}


int main()
{
	Circle C;				//Define a structure variable.

	//Get data about the circle.
	C = getInfo();

	//Calculate the circle's area.
	C.area = PI * pow(C.radius, 2.0);

	//Display the circle data.
	cout << "\nThe radius and area of the circle are: \n";
	cout << fixed << showpoint << setprecision(2);
	cout << "Radius: " << C.radius << endl;
	cout << "Area: " << C.area << endl;

	return 0;
}



