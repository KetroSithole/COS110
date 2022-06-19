//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_LINEARSTRUCTURE_H
#define ASSIGNMENT_4_LINEARSTRUCTURE_H
#include <iostream>

using namespace std;

template<class T>
class LinearStructure;

template<class T>
ostream& operator<<(ostream&,LinearStructure<T>&);

template<class T>
class LinearStructure
{
public:
    /*
    Calls print() function to print the data
    */
    friend ostream& operator<< <T>(ostream& os,LinearStructure<T>& l);

    virtual ~LinearStructure(){}

    /*
    Creates a dynamically allocated deep copy of the object and returns
    a pointer to it
    */
    virtual LinearStructure<T>* clone() = 0;

    /*
    Inserts an element at the given index.
    See subclasses for more details.
    */
    virtual void insert(int index, T element) = 0;

    /*
    Removes and returns an element from the index passed
    as a parameter.  See subclasses for more details.
    */
    virtual T remove(int index) = 0;

    /*
    Returns an element from the index passed
    as a parameter.  See subclasses for more details.
    */
    virtual T get(int index) const = 0;

    /*
    Returns true if the list is empty, and false
    otherwise.
    */
    virtual bool isEmpty() = 0;

    /*
    Empties out the structure.  See subclasses for more details.
    */
    virtual void clear() = 0;

protected:

    /*
    Stream operators are not members of a class and are
    therefore not inherited and cannot be overridden as
    subclass members.  See the implementation of this
    class' stream operator below.  The print function
    in each subclass should be implemented as you would
    an overloaded stream operator.
    */
    virtual ostream& print(ostream& os) = 0;

};

template<class T>
ostream& operator<<(ostream& os,LinearStructure<T>& l)
{l.print(os); return os;}
#endif //ASSIGNMENT_4_LINEARSTRUCTURE_H

