#include "Rectangle.h"

void Rectangle::setWidth(double w){
    if (w >= 0)
        width = w;
    else
        throw NegativeSize();
}

void Rectangle::setLength(double l){
    if (l >= 0)
        length = l;
    else
        throw NegativeSize();
}