//This program stores data about a circle in a structure.
#include <iostream>
#include <cmath>			//For the pow function
#include <iomanip>

using namespace std;

//Constant for pi.
const double PI = 3.14159;

//Structure Declaration
struct Circle
{
	double radius;			//A circle's radius
	double diameter;		//A circle's diameter
	double area;			//A circle's area.
};


int main()
{
	Circle C;			//Define a structure variable.

	//Get the circle's diameter.
	cout << "Enter the diameter of a circle: ";
	cin >> C.diameter;

	//Calculate the circle's radius.
	C.radius = C.diameter / 2;

	//Calculate the circle's area.
	C.area = PI * pow(C.radius, 2);

	//Display the circle data.
	cout << fixed << showpoint << setprecision(2);
	cout << "\nThe radius and the area of the circle are: ";
	cout << "Radius: " << C.radius << endl;
	cout << "Area: " << C.area << endl;

	return 0;
}