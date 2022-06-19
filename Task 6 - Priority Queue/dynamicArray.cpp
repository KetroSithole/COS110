#include "dynamicArray.h"




//Constructor
template <class T>
DynamicArray<T>::DynamicArray(int s)
{
	if (s <= 0)
		throw "Invalid size provided";
	else
	{
		size = s;
		elements = new T*[size];
		for (int index=0;	index<size;		index++)
			elements[index] = nullptr;
		numElements = 0;
	}
}




//Copy constructor
template <class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &other)
{
	size = other.size;
	numElements = other.numElements;

	elements = new T*[size];
	for (int index=0;	index<size;		index++)
	{
		if (other.elements[index] != nullptr)
			elements[index] = new T(*(other.elements[index]));
		else
			elements[index] = nullptr;
	}
}




//Overload assignment operator
template <class T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &other)
{
	if (this != &other)
	{
		for (int index=0;	index<size;	index++)
			delete elements[index];
		delete [] elements;

		size = other.size;
		numElements = other.numElements;

		elements = new T*[size];
		for (int index=0;	index<size;		index++)
		{
			if (other.elements[index] != nullptr)
				elements[index] = new T (*(other.elements[index]));
			else
				elements[index] = nullptr;
		}
	}
	return *this;
}




//Clone
template <class T>
DynamicArray<T> *DynamicArray<T>::clone()
{
	DynamicArray<T> *clone = new DynamicArray<T>(this->size);

	clone->numElements = this->numElements;
	clone->size = this->size;

	for (int index=0;	index<size;		index++)
	{
		if (this->elements[index] != nullptr)
			clone->elements[index] = new T (*(this->elements[index]));
		else
			clone->elements[index] = nullptr;
	}
	return clone;
}




//Destructor
template <class T>
DynamicArray<T>::~DynamicArray()
{
	clear();
	delete [] elements;
}




//Insert
template<class T>
void DynamicArray<T>::insert(int index, T element)
{
	DynamicArray<T> oldElements(*this);
	int oldSize = size;

	if (index < size && elements[index] == nullptr)
		elements[index] = new T(element);
	else if (elements[size-1] != nullptr)
	{
		DynamicArray<T> oldElements = *this;
	
		clear();
		delete [] elements;
		
		elements = new T * [size+1];
		for (int index=0;	index<size+1;	index++)
		{
			if (index<size && oldElements.elements[index] != nullptr)
				elements[index] = new T(*oldElements.elements[index]);
			else
				elements[index] = nullptr;
		}
		resize(size);
	}
	else if(index >= size)
	{
		DynamicArray<T> oldElements = *this;
	
		clear();
		delete [] elements;
	
		elements = new T * [index+1];
		for (int i=0;	i<index+1;	i++)
		{
			if (i<size && oldElements.elements[i] != nullptr)
				elements[i] = new T(*oldElements.elements[i]);
			else
				elements[i] = nullptr;
		}
		resize(index);
	}
	elements[index] = new T(element);
	int yIndex=0;
	for (int xIndex=0;	xIndex<size;	xIndex++)
	{
		if (xIndex == index)
			yIndex--;
		else if(yIndex<oldSize && oldElements.elements[yIndex] != nullptr)
		{
			delete elements[xIndex];
			elements[xIndex] = new T(*oldElements.elements[yIndex]);
		}
		yIndex++;
	}
	numElements++;
}




//Remove
template <class T>
T DynamicArray<T>::remove(int index)
{
	if (elements[index] == nullptr)
		throw "empty structure";

	T *item = new T (*(elements[index]));
	
	delete elements[index];
	elements[index] = nullptr;

	for (int count=index+1;	count<size;	count++)
	{
		if (index == size-1)
			break;
		else
			elements[count-1] = elements[count];
		if (count == size-1)
			elements[count] = nullptr;
	}
	numElements--;
	return *item;
}




//Getter
template <class T>
T DynamicArray<T>::get(int index) const
{
	if (elements[index] == nullptr)
		throw "empty structure";
	return *elements[index];
}




//Empty checker
template <class T>
bool DynamicArray<T>::isEmpty()
{
	int count = 0;
	for (int index=0;	index<size;		index++)
	{
		if (elements[index] == nullptr)
			count++;
	}

	if (count == size)
		return true;
	return false;
}




//Clear
template <class T>
void DynamicArray<T>::clear()
{
	for (int index=0;	index<size;		index++)
	{
		delete elements[index];
		elements[index] = nullptr;
	}
	numElements = 0;
}




//Overloaded extraction operator
template <class T>
ostream &operator<< (ostream &os ,DynamicArray<T> &obj)
{
	obj.print(os);
	return os;
}




//Print
template <class T>
ostream &DynamicArray<T>::print(ostream& os)
{
	os << "[";
	for (int index=0;	index<size;		index++)
	{
		if (elements[index] == nullptr)
		{
			if (index == size -1)
				os << "*";
			else
				os << "*,";
		}
		else
		{
			if (index == size -1)
				os << *(elements[index]);
			else
				os << *(elements[index]) <<",";
		}
	}
	os << "]";
	return os;
}




//Resize
template<class T>
void DynamicArray<T>::resize(int howMuch)
{
	this->size = howMuch+1;
}
