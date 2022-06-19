#ifndef ASSIGNMENT_4_CIRCULARLIST_H
#define ASSIGNMENT_4_CIRCULARLIST_H


#include "linearStructure.h"
#include "node.h"

template<class T>
class CircularList;

template<class T>
ostream& operator<<(ostream&,CircularList<T>&);

template<class T>
class CircularList : public LinearStructure<T>
{
public:
    /*
    The overloaded stream operator.  This function should return a string representation of the list.  Elements should be comma separated and appear between square brackets.  If the list contains the elements x, y, and z, then the string returned should be [x,y,z] with no additional whitespace/new lines.
    */
    friend ostream& operator<< <T>(ostream&,CircularList<T>&);

    /*
    The constructor initializes an empty list.
    */
    CircularList();

    /*
    The copy constructor.
    */
    CircularList(const CircularList<T>& other);

    /*
    The overloaded assignment operator.
    */
    CircularList<T>& operator=(const CircularList<T>& other);

    /*
    Creates a dynamically allocated deep copy of the object and returns
    a pointer to it
    */
    virtual CircularList<T>* clone();

    /*
    The destructor.
    */
    virtual ~CircularList();

    /*The following holds for this function:

    1.) It is valid to insert at index 0 into an empty list

    2.) If the index supplied is the size of the list, then append the element to the back of the list.

    3.) Any index that is smaller than the size of the list, except for negative numbers, is valid.

    4.) For an invalid index, throw "invalid index" string.
    */
    virtual void insert(int index, T element);

    /*
    Removes and returns the element at the index passed in
    as a parameter.    If an invalid delete is attempted
    throw the string "empty structure".
    */
    virtual T remove(int index);

    /*
    Returns the element at the index passed in as a parameter. The element
    is not removed from the data structure. If an invalid index is provided
    throw the string "empty structure".
    */
    virtual T get(int index) const;

    /*
    Returns true if the list is empty and false otherwise.
    */
    virtual bool isEmpty();

    /*
    Removes all of the nodes from the list.  After this function has
    been called on a CircularList object, the list must be empty.
    */
    virtual void clear();

    /*
    Returns a pointer to the first element, not the element at the front of the list.
    */
    Node<T>* getLeader();

protected:
    ostream& print(ostream& os);


private:
    //Returns the number of nodes in the list
    int size() const;

    //The last node in the cirular list.
    Node<T>* tail;
};


#endif //ASSIGNMENT_4_CIRCULARLIST_H
