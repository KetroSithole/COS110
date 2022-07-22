#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle
{
    private:
        double width;
        double length;

    public:
        //Default constructor
        Rectangle(){
            width = 0.0;
            length = 0.0;
        }

        //Constructor #2
        Rectangle (double w, double l){
            width = w;
            length = l;
        }

        double getWidth () const{
            return width;
        }

        double getLength () const{
            return length;
        }

        double getArea () const{
            return length * width;
        }
};
#endif