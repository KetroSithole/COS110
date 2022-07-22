//This program demonstrates Rectangle class exceptions.
#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(int argc, char *const argv[])
{
    double width;                                       //Rectangle's width.
    double length;                                      //Rectangle's length.
  
    //Create a Rectangle object.
    Rectangle myRectangle;

    //Get the rectangle's width and length.
    cout << "Enter the rectangle's width: ";
    cin >> width;
    cout << "Enter the rectangle's length: ";
    cin >> length;

    //Store the width in the myRectangle object.
    try
    {
        myRectangle.setWidth(width);
        myRectangle.setLength(length);
            
    }  
    catch(Rectangle::NegativeLength e)
    {
        cout << "Error: " << e.getValue() << " is an invalid value for the rectangle's length.\n";
    }
    catch(Rectangle::NegativeWidth e)
    {
        cout << "Error: " << e.getValue() << " is an invalid value for the rectangle's width.\n";
    }

    cout << "End of the program.\n";
    return 0;
}