#ifndef SIMPLEVECTOR_CPP
#define SIMPLEVECTOR_CPP


//Constructor for the SimpleVector class. Sets the size of the array and allocates memory for it.
template <class T>
SimpleVector<T>::SimpleVector (int s){
    arraySize = s;

    //Allocate memory of the array.'
    try{
        aptr = new T [s];
    }
    catch(bad_alloc){
        memError();
    }

    //Initialize the array.
    for (int index=0;   index < arraySize;    index++)
        *(aptr + index) = 0;
}


//Copy Constructor for the SimpleVector class.
template <class T>
SimpleVector<T>::SimpleVector (const SimpleVector &obj){
    //Copy the array size
    arraySize= obj.arraySize;

    //Allocate memory for the array.
    aptr= new T [arraySize];
    if (aptr == 0)
        memError();

    //Copy the elements of obj's array.
    for (int index=0;   index < arraySize;  index++)
        *(aptr + index) = *(obj + index);
}


//Destructor for the SimpleVector class.
template <class T>
SimpleVector<T>::~SimpleVector (){
    if (arraySize > 0)
        delete [] aptr;
}


/*
***********************************************************************************************
    memError function.                                                                        *
    Displays an error message and terminates the program when memory allocation fails.        *
***********************************************************************************************
*/
template <class T>
void SimpleVector<T>::memError(){
    cout << "ERROR: Cannot allocate memory.\n";
    exit (EXIT_FAILURE);
}


/*
****************************************************************************************************
    subError function.                                                                             *
    Displays an error message and terminates the program when memory a subscript is out of range.  *        *
****************************************************************************************************
*/
template <class T>
void SimpleVector<T>::subError(){
    cout << "ERROR: Subscript out of range.\n";
    exit (EXIT_FAILURE);
}


/*
**********************************************************************************
    getElementAt function.                                                       *
    The argument is a subscript.                                                 *
    This function returns the value stored at the subscript in the array.        *
**********************************************************************************
*/
template <class T>
T SimpleVector<T>::getElementAt (int position){
    if (position < 0 || position >= arraySize)
        subError();
    return aptr[position];
}


/*
**************************************************************************************************
    Overload [] operator.                                                                        *
    The argument returns a reference to the element in the array indexed by the subscript.       *
**************************************************************************************************
*/
template <class T>
T &SimpleVector<T>::operator[] (const int &position){
    if (position < 0 || position >= arraySize)
        subError();
    return aptr[position];
} 

#endif