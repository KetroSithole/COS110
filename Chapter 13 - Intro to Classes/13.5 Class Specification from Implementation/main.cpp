#include "Rectangle.h"
#include <iostream>
#include <memory>

using namespace std;


void Rectangle::setWidth(double x){
	if (x>=0){
		width = x;
	}
	else{
		cout << "Invalid width. \n";
		exit(0);
	}
	
}

void Rectangle::setLength(double y){
	if (y>=0){
		length = y;
	}
	else{
		cout << "Invalid length. \n";
		exit(0);
	}
	
}

double Rectangle::getWidth() const{
	return width;
}

double Rectangle::getLength() const{
	return length;
}

double Rectangle::getArea() const{
	return width * length;
}

int main(int argc, char const *argv[])
{
	unique_ptr<Rectangle> box(new Rectangle);
	double w;
	double l;

	cout << "Enter the rectangle's width: ";
	cin >> w;
	box->setWidth(w);
	cout << "Enter the rectangle's length: ";
	cin >> l;
	box->setLength(l);

	cout << "\nArea: " << box->getArea() << endl;
 
	return 0;
}	