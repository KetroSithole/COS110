//
// Created by DitFred on 10/30/2020.
//

#ifndef ASSIGNMENT_4_DYNAMICARRAY_H
#define ASSIGNMENT_4_DYNAMICARRAY_H


#include "linearStructure.h"

template<class T>
class DynamicArray;

template<class T>
ostream& operator<<(ostream&,DynamicArray<T>&);

template<class T>
class DynamicArray : public LinearStructure<T>
{
public:
    /*The overloaded stream operator for the DynamicArray class.  If
    an array object is printed that contains the elements a,c,b and m,
    with element 'a' at index 0 and element 'm' at index 3 (first to last),
    the output MUST be in the following format:
    [a,c,b,m]
    with no white space or new lines.

    It is possible that some of the elements might be null.  If this is the
    case then the null elements should be indicated with asterisks.
    If the array contains the elements a and m,
    with element 'a' at index 0 and element 'm' at index 3 (first to last),
    the output MUST be in the following format:
    [a,*,*,m]

    NOTE: if all elements are null, output asterisks. If the array is of size 4,
    but containts no elements yet, the output MUST be in the following format:
    [*,*,*,*]
    */
    friend ostream& operator<< <T>(ostream&,DynamicArray<T>&);

    /*
    The constructor accepts the initial size of the array.
    All elements in the array are initialized to null.
    If a size <= 0 is provided, throw an exception message "Invalid size provided"
    */
    DynamicArray(int s);

    /*
    The copy constructor.
    */
    DynamicArray(const DynamicArray<T>& other);

    /*
    The overloaded assignment operator.
    */
   DynamicArray<T>& operator=(const DynamicArray<T>& other);

    /*
    Creates a dynamically allocated deep copy of the object and returns
    a pointer to it
    */
    virtual DynamicArray<T>* clone();

    /*
    The destructor.
    */
    virtual ~DynamicArray();

    /*
    Inserts an element at the given index in the array.  If
    the index is larger than the size of the array, grow
    the array to accomodate the index.

    NOTE: a value can only be inserted at a given index if the
    given index does not store a value yet. If the index position
    is occupied, all elements from the given index onwards
    are shifted one position forward to free the requested position.

    Eg: Array object stores [a,c,b,m]. A request is made to insert 'j'
    at location '1'. Currently, 'c' is stored there. All elements are shifted
    forward: [a,*,c,b,m], and 'j' is put in the now open position '1':
    [a,j,c,b,m]. Note that the array had to be resized to accomodate the insertion.
    */
    virtual void insert(int index, T element);

    /*
    Removes and returns the element at the index passed in
    as a parameter.  All elements from the removed index onwards
    are shifted one position backward. Array is not resized. If an element is null,
    throw the string "empty structure".
    */
    virtual T remove(int index);

    /*
    Returns the element at the index passed in as a parameter.
    The element is not removed from the data structure. If an element
    is null, throw the string "empty structure".
    */
    virtual T get(int index) const;

    /*
    Returns true if the array contains no elements and
    false otherwise.
    */
    virtual bool isEmpty();

    /*
    Removes all of the elements from the array.  After this function has
    been called on a DynamicArray object, the the array must be empty (i.e. all elements in the array must be null).  The array's current
    size remains unchanged.
    */
    virtual void clear();

protected:
    ostream& print(ostream& os);


private:
    /*
    Use this function to resize the array.
    */
    void resize(int howMuch);

    /*
    An array of pointers to objects of type T.
    The elements should be stored in this array.
    */
    T ** elements;

    /*
    The current size of the array.  It should be initialized
    appropriately in the constructor.
    */
    int size;

    /*
    The number of elements currently contained in the array.
    */
    int numElements;
};

#endif //ASSIGNMENT_4_DYNAMICARRAY_H
