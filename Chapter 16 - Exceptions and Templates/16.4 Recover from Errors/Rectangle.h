//Specification file for rectangle class
#ifndef RECTANGLE_H
#define RECTANGLE_H

//Rectangle class declaration
class Rectangle
{
	private: 
		double width;
		double length;

	public:

        //Exception class for negative width
        class NegativeWidth{
        };

         //Exception class for negative length
        class NegativeLength{
        };

        //Default constructor.
        Rectangle(){
            width = 0.0;
            length = 0.0;
        }

        //Mutator functions defined in Rectnagle.cpp
		void setWidth (double);
		void setLength (double);

        //Accessor functions.
		double getArea () const{
            return width * length;
        }

		double getWidth () const{
            return width;
        }

		double getLength () const{
            return length;
        }
};
#endif