#include "orderedContainer.h"




//Constructor
template <class T>
OrderedContainer<T>::OrderedContainer(LinearStructure<T>* c)
{
	dataStructure = c;
}




//Copy Constructor
template <class T>
OrderedContainer<T>::OrderedContainer(const OrderedContainer<T>& other)
{
	dataStructure = other.dataStructure;
}




//Overload Assignment Operator
template <class T>
OrderedContainer<T> &OrderedContainer<T>::operator=(const OrderedContainer<T>& other)
{
	if (this != &other)
	{
		delete dataStructure;
		dataStructure = other.dataStructure;
	}
	return *this;
}




//Destructor
template <class T>
OrderedContainer<T>::~OrderedContainer()
{
	dataStructure->clear();
}




//isEmpty
template <class T>
bool OrderedContainer<T>::isEmpty()
{
	if (dataStructure->isEmpty())
		return true;
	return false;
}




//Get Implementation
template <class T>
LinearStructure<T> *OrderedContainer<T>::getImplementation()
{
	return dataStructure;
}

