//SimpleVector class template
#ifndef SIMPLEVECTOR_H
#define SIMPLEVECTOR_H
#include <iostream>
#include <new>              //Needed for bad_alloc exception
#include <cstdlib>          //Needed for the exit function

using namespace std;

template <class T>
class SimpleVector
{
    private:
        T *aptr;                //To point to the allocated array
        int arraySize;          //Number of elements in the array
        void memError ();        //Handles memory allocation errors
        void subError ();        //Handles subscripts out of range

    public:
        //Default constructor
        SimpleVector (){
            aptr = 0;
            arraySize = 0;
        }

        //Constructor declaration
        SimpleVector (int);

        //Copy Constructor declaration
        SimpleVector (const SimpleVector &);

        //Destructor declaration
        ~SimpleVector ();

        //Accessor to return the array size
        int size() const{
            return arraySize;
        }

        //Accessor to return a specific element
        T getElementAt (int position);

        //Overload [] operator decalaration
        T &operator[] (const int &); 
};

#include "SimpleVector.cpp"

#endif
