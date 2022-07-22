//This program demonstrates passing arguments to a base class constructor.
#include "Box.h"
#include <iostream>

using namespace std;

int main()
{
    double boxWidth;                //To hold box's width
    double boxLength;               //To hold box's length
    double boxHeight;               //To hold box's height

    //Get the box's width, length and height from the user.
    cout << "Enter the dimensions of a box:\n";
    cout << "Width: ";
    cin >>  boxWidth;
    cout << "Length: ";
    cin >>  boxLength;
    cout << "Height: ";
    cin >>  boxHeight;

    //Define a Box object.
    Box myBox (boxWidth, boxLength, boxHeight);

    //Display the Box object's properties.
    cout << "\nHere are the properties:\n";
    cout << "Width: " << myBox.getWidth() << endl;
    cout << "Length: " << myBox.getLength() << endl;
    cout << "Height: " << myBox.getHeight() << endl;
    cout << "Base Area: " << myBox.getArea() << endl;
    cout << "Volume: " << myBox.getVolume() << endl;
    return 0;
}