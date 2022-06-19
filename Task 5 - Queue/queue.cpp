#include "queue.h"




//Constructor
template <class T>
Queue<T>::Queue(LinearStructure<T>* c) : OrderedContainer<T>(c)
{
	front = 0;
	rear = 0;
}




//Copy constructor
template <class T>
Queue<T>::Queue(const Queue<T>& other) : OrderedContainer<T>(other)
{
	this->front = other.front;
	this->rear = other.rear;
}




//Overloaded assignment operator.
template <class T>
Queue<T> &Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		this->dataStructure = other.dataStructure;
		this->front = other.front;
		this->rear = other.rear;
	}
	return *this;
}




//Destructor.
template <class T>
Queue<T>::~Queue()
{
	this->dataStructure->clear();
}




//Remove
template <class T>
T Queue<T>::remove()
{
	T toReturn = this->dataStructure->get(front);
	this->dataStructure->remove(front);
	rear--;
	return toReturn;
}

    


//Return top
template <class T>
T Queue<T>::next()
{
	return this->dataStructure->get(front);
}




//Insert
template <class T>
void Queue<T>::insert(T el)
{
	this->dataStructure->insert(rear++, el);
}




//Reverse
template <class T>
void Queue<T>::reverse()
{
	std::cout << "Rear: " << rear << std::endl;
	T *newQueue = new T[rear];

	for (int index=0;	index<rear;	index++)
		newQueue[index] =  this->dataStructure->get(index);
	this->dataStructure->clear();

	for (int index=0;	index<rear;	index++)
		this->dataStructure->insert(0,newQueue[index]);
}