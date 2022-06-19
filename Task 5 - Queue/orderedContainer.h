//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_ORDEREDCONTAINER_H
#define ASSIGNMENT_4_ORDEREDCONTAINER_H

#include "linearStructure.h"

template<class T>
class OrderedContainer
{

public:
    /*
    The constructor initializes the Container
    with the structure passed in as a parameter.
    This is how the constructor will be used:
    Stack<int> myStack(new CircularList<int>());
    // or any other LinearStructure object
    */
    OrderedContainer(LinearStructure<T>* c);

    /*
    Copy constructor
    */
    OrderedContainer(const OrderedContainer<T>& other);

    /*
    Overloaded assignment operator.
    */
    virtual OrderedContainer<T>& operator=(const OrderedContainer<T>& other);

    /*
    Destructor.
    */
    virtual ~OrderedContainer();

    /*
    Removes an element from the container.  See subclasses
    for more details.
    */
    virtual T remove() = 0;

    /*
    Returns an element from the container.  See subclasses
    for more details.
    */
    virtual T next() = 0;

    /*
    Inserts an element into the container.  See subclasses
    for more details.
    */
    virtual void insert(T el) = 0;

    /*
    Returns true if the container is empty, and false
    if the container contains elements.
    */
    virtual bool isEmpty();

    /*
    This function reverses the order of the elements
    in the container.
    */
    virtual void reverse() = 0;


    /*
    Returns a pointer to the linear structure in which the elements
    are contained.
    */
    virtual LinearStructure<T>* getImplementation();

protected:
    /*
    A pointer to an object of type LinearStructure.  This
    structure should contain the elements inserted into
    the container.  This member should be initialized
    in the constructor.
    */
    LinearStructure<T>* dataStructure;
};


#endif //ASSIGNMENT_4_ORDEREDCONTAINER_H
