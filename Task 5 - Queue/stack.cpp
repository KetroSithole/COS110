#include "stack.h"




//Constructor
template <class T>
Stack<T>::Stack(LinearStructure<T>* c) : OrderedContainer<T>(c)
{
	stackTop = -1;
}




//Copy constructor
template <class T>
Stack<T>::Stack(const Stack<T>& other) : OrderedContainer<T>(other)
{
	stackTop = other.stackTop;
}




//Overloaded assignment operator.
template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T>& other)
{
	if (this != &other)
	{
		this->dataStructure = other.dataStructure;
		stackTop = other.stackTop;
	}
	return *this;
}




//Destructor.
template <class T>
Stack<T>::~Stack()
{
	this->dataStructure->clear();
}




//Remove
template <class T>
T Stack<T>::remove()
{
	T toReturn = this->dataStructure->get(stackTop);
	this->dataStructure->remove(stackTop);
	stackTop--;
	return toReturn;
}

    


//Return top
template <class T>
T Stack<T>::next()
{
	return this->dataStructure->get(stackTop);
}




//Insert
template <class T>
void Stack<T>::insert(T el)
{
	stackTop++;
	this->dataStructure->insert(stackTop,el);
}




//Reverse
template <class T>
void Stack<T>::reverse()
{
	int oldStackTop = stackTop;
	T *newStack = new T[oldStackTop];

	for (int index=0;	index<stackTop+1;	index++)
		newStack[index] =  this->dataStructure->get(index);
	this->dataStructure->clear();
	stackTop = oldStackTop;

	for (int index=0;	index<stackTop+1;	index++)
		this->dataStructure->insert(0,newStack[index]);
} 