#include "linkedList.h"





//Constructor
template <class T>
LinkedList<T>::LinkedList()
{
	head = nullptr;
}




//Copy Constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
{
	head = nullptr;
    Node<T> *otherNode = other.head;
    int count = 0;
    while (otherNode != nullptr)
    {
       insert(count,otherNode->element);
       otherNode = otherNode->next;
       count++;
    }
}




//Overload assignment operator
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &other)
{
	if (this != &other)
	{
		head = nullptr;
		Node<T> *otherNode = other.head;
		int count = 0;
    	while (otherNode != nullptr)
    	{
       		insert(count,otherNode->element);
       		otherNode = otherNode->next;
       		count++;
    	}
	}
    return *this;
}




//Clone
template <class T>
LinkedList<T> *LinkedList<T>::clone()
{
	LinkedList<T> *clonedObject = new LinkedList<T>();
	Node<T> *otherNode = this->head;
    int count = 0;
    while (otherNode != nullptr)
    {
       clonedObject->insert(count,otherNode->element);
       otherNode = otherNode->next;
       count++;
    }
    return clonedObject;
}




//Destructor
template <class T>
LinkedList<T>::~LinkedList()
{
	clear();
}




//Insert
template <class T>
void LinkedList<T>::insert(int index, T element)
{
	if (index < 0 || index > size())
		throw "invalid index";

	Node<T> *newNode = new Node<T>(element);
	Node<T> *nodePtr = head, *previousPtr = nullptr;


	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else
	{
		for (int count=0;	count<index;	count++)
		{
			previousPtr = nodePtr;
			nodePtr = nodePtr->next;
		}
	
		if (index == 0 && previousPtr == nullptr)
		{
			head = newNode;
			newNode->next = nodePtr;
		}
		else if (index == size()-1)
		{
			nodePtr->next = newNode;
		}
		else
		{
			previousPtr->next = newNode;
			newNode->next = nodePtr;
		}
	}
}




//Remove
template <class T>
T LinkedList<T>::remove(int index)
{
	if (index < 0 || index > size() || head == nullptr)
		throw "empty structure";
	else
	{
		Node<T> *temp = head->next;
		Node<T> *toReturn;
		Node<T> *nodePtr = head;
		Node<T> *previousPtr = nullptr;

		if (index == 0)
		{
			toReturn = head;
			delete head;
			head = temp;
		}
		else
		{
			for (int count=0;	count<index;	count++)
			{
				previousPtr = nodePtr;
				nodePtr = nodePtr->next;
			}

			previousPtr->next = nodePtr->next;
			toReturn = nodePtr;
			delete nodePtr;
		}

		return toReturn->element;
	}
}




//Getter
template <class T>
T LinkedList<T>::get(int index) const
{
	Node<T> *nodePtr = nullptr;
    if (index > size() || index < 0 || head == nullptr)
        throw "empty strucutre";
    else
    {
        nodePtr = head;
        for (int count=0;   count<index;    count++)
            nodePtr = nodePtr->next;
    }
    return nodePtr->element;
}




//Empty 
template <class T>
bool LinkedList<T>::isEmpty()
{
	if (head == nullptr)
		return true;
	return false;
}




//Clear
template <class T>
void LinkedList<T>::clear()
{
	Node<T> *nodePtr = head;   
	Node<T> *nextNode = nullptr;  

	while (nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
	head = nullptr;
}




//Head Getter
template <class T>
Node<T> *LinkedList<T>::getLeader()
{
	return head;
}




//Size Getter
template <class T>
int LinkedList<T>::size()const
{
	Node<T> *nodePtr = head;
	int size = 0;
	while (nodePtr != nullptr)
	{
		size++;
		nodePtr = nodePtr->next;
	}
	return size;
}




//Print
template <class T>
ostream &LinkedList<T>::print(ostream& os)
{
	Node<T> *nodePtr = head;

	os << "[";
	while (nodePtr != nullptr)
	{
		if (nodePtr->next == nullptr)
			os << nodePtr->element;
		else
			os << nodePtr->element << ",";
		nodePtr = nodePtr->next;
	}
	os << "]";
	return os;
}




//Extraction Operator Overload
template <class T>
ostream &operator<<(ostream &os, LinkedList<T> &obj)
{
	obj.print(os);
	return os;
}

