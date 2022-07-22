#include <iostream>

using namespace std;

class Rectangle
{
	private:

		double width;
		double length;

	public:

		Rectangle (double w, double l){
			width = w;
			length = l;
		}

		double getLength() const{
			return length;
		}

		double getWidth() const{
			return width;
		}

};



int main(int argc, char const *argv[])
{
	Rectangle box1(10.0, 20.0);
	Rectangle box2(20.0, 40.0);

	box2 = box1;

	cout << box2.getWidth() << " " << box2.getLength() << endl;
	return 0;
}