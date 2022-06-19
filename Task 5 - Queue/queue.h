//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_QUEUE_H
#define ASSIGNMENT_4_QUEUE_H


#include "orderedContainer.h"
#include "linearStructure.h"

template<class T>
class Queue : public OrderedContainer<T>
{
public:
    /*
    The constructor initializes the Queue with
    the structure which will contain the elements.
    */
    Queue(LinearStructure<T>* c);

    /*
    Copy constructor
    */
    Queue(const Queue<T>& other);

    /*
    Overloaded assignment operator.
    */
    Queue<T>& operator=(const Queue<T>& other);

    /*
    Destructor.
    */
    virtual ~Queue();

    /*
    This function removes and returns the element
    at the front of the Queue.
    */
    virtual T remove();

    /*
    This function returns, but does NOT remove, the
    element at the front of the queue.
    */
    virtual T next();

    /*
    This function places the element sent in as a
    parameter at the back of the Queue.
    */
    virtual void insert(T el);

    /*
    This function reverses the order of the elements
    in the queue.  For example, if the stack contains the
    elements w, x, y and z, where w is at the front (first element)
    of the queue, then the queue should be z, y, x, w after the
    reverse with z now being at the front of the queue.
    */
    virtual void reverse();

protected:
    /*
    This varibale maintains the front end of the queue
    */
    int front;
    /*
    This varibale maintains the rear end of the queue
    */
    int rear;
};


#endif //ASSIGNMENT_4_QUEUE_H
