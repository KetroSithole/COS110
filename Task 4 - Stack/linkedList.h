//
// Created by DitFred on 10/29/2020.
//

#ifndef ASSIGNMENT_4_LINKEDLIST_H
#define ASSIGNMENT_4_LINKEDLIST_H


#include "linearStructure.h"
#include "node.h"

template<class T>
class LinkedList;

template<class T>
ostream& operator<<(ostream&,LinkedList<T>&);

template<class T>
class LinkedList : public LinearStructure<T>
{
public:
    /*The overloaded stream operator for the List class.  If
    a List object is printed and contains the elements a,c,b and m, with
    element 'a' at index 0 and element 'm' at index 3 (first to last), the
    output MUST be in the following format:
    [a,c,b,m]
    with no white space or new lines.

    NOTE: if the list is empty, output empty square brackets:
    []
    */
    friend ostream& operator<< <T>(ostream&,LinkedList<T>&);

    /*
    The constructor initializes an empty list.
    */
    LinkedList();

    /*
    The copy constructor.
    */
    LinkedList(const LinkedList<T>& other);

    /*
    The overloaded assignment operator.
    */
    LinkedList<T>& operator=(const LinkedList<T>& other);

    /*
    Creates a dynamically allocated deep copy of the object and returns
    a pointer to it
    */
    virtual LinkedList<T>* clone();

    /*
    The destructor.
    */
    virtual ~LinkedList();

    /*
    Inserts an element at the given index.  The following holds
    for this function:

    1.) It is valid to insert at index 0 of an empty list.

    2.) It is valid to insert at the index returned by size().  Simply
        append the element to the back of the list.

    3.) Only indices between 0 and size() are valid.

    4.) For an invalid index, throw an exception message "invalid index"
    */
    virtual void insert(int index, T element);

    /*
    Removes and returns the element at the index passed in
    as a parameter. If an invalid delete is attempted
    throw the string "empty structure".
    */
    virtual T remove(int index);

    /*
    Returns the element at the index passed in
    as a parameter. The element is not removed from the data structure.
    If an invalid index is given, throw the string "empty structure".
    */
    virtual T get(int index) const;

    /*
    Returns true if the list is empty, and false
    otherwise.
    */
    virtual bool isEmpty();

    /*
    Removes all of the nodes from the list.  After this function has
    been called on a LinkedList object, the list must be empty.
    */
    virtual void clear();

    /*
    Returns the head, not the element at the head.
    */
    Node<T>* getLeader();

protected:
    ostream& print(ostream& os);

private:
    //Returns the number of nodes in the list.
    int size() const;

    //The first node in the list,
    Node<T>* head;
};


#endif //ASSIGNMENT_4_LINKEDLIST_H
