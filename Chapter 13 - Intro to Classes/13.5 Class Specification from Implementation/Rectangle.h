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
		void setWidth (double);
		void setLength (double);
		double getArea () const;
		double getWidth () const;
		double getLength () const; 	
};

#endif