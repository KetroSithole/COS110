#include "circularList.h"





//Constructor
template <class T>
CircularList<T>::CircularList()
{
    tail = nullptr;
}




//Copy Constructor
template <class T>
CircularList<T>::CircularList(const CircularList<T> &other)
{
    tail = nullptr;
    Node<T> *otherNode = other.tail->next;
    int count = 0;
    do
    {
        insert(count,otherNode->element);
        otherNode = otherNode->next;
        count++;
    }
    while (otherNode != other.tail->next);
 
}




//Overload assignment operator
template <class T>
CircularList<T> &CircularList<T>::operator=(const CircularList<T> &other)
{
    if (this != &other)
    {
        tail = nullptr;
        Node<T> *otherNode = other.tail->next;
        int count = 0;
        do
        {
            insert(count,otherNode->element);
            otherNode = otherNode->next;
            count++;
        }
        while (otherNode != other.tail->next);
    }
    return *this;
}




//Clone
template <class T>
CircularList<T> *CircularList<T>::clone()
{
    CircularList<T> *clonedObject = new CircularList<T>();
    Node<T> *otherNode = this->tail->next;
    int count = 0;
    do
    {
       clonedObject->insert(count,otherNode->element);
       otherNode = otherNode->next;
       count++;
    }
     while (otherNode != this->tail->next);
    return clonedObject;
}




//Destructor
template <class T>
CircularList<T>::~CircularList()
{
    clear();
}




//Insert
template <class T>
void CircularList<T>::insert(int index, T element)
{
    if (index < 0 || index > size())
        throw "invalid index";

    Node<T> *newNode = new Node<T>(element);
    if (!tail)
    {
        tail = newNode;
        newNode->next = tail;
    }
    else if (index == 0)
    {
        newNode->next = tail->next;
        tail->next = newNode;
    }
    else if (index == size())
    {
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
    else
    {
        Node<T> *nodePtr = tail->next;
        Node<T> *previousPtr = nullptr;
        for (int i=0;   i<index;    i++)
        {
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        newNode->next = nodePtr;
        previousPtr->next = newNode;
    }
}




//Remove
template <class T>
T CircularList<T>::remove(int index)
{
    
    if (index < 0 || index > size() || tail == nullptr)
        throw "empty structure";

    if (size() == 1)
    {
        Node<T> *temp = tail;
        tail = nullptr;
        return temp->element;
    }
    else if (tail->next == tail)
    {

        Node<T> *temp = tail;
        delete tail;
        tail == nullptr;
        return temp->element;
    }
    
    else 
    {
        Node<T> *nodePtr = tail->next;
        Node<T> *previousPtr = nullptr;
        Node<T> *temp = nullptr;
        for (int i=0;   i<index;    i++)
        {
            previousPtr = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (index == size()-1)
        {
            T toReturn = tail->element;
            previousPtr->next = nodePtr->next;
            tail = nullptr;
            delete nodePtr;
            tail = previousPtr;     
            return toReturn;
        }
        else if (index == 0)
        {
            nodePtr = tail->next;
            T toReturn = nodePtr->element;
            tail->next = nodePtr->next;
            delete nodePtr;
            return toReturn;
        }
        else
        {
            T toReturn = nodePtr->element;
            previousPtr->next = nodePtr->next;
            delete nodePtr;
            return toReturn;
        }
    }
}




//Getter
template <class T>
T CircularList<T>::get(int index) const
{
    if (index > size() || index < 0 || tail == nullptr)
        throw "empty structure";
    else
    {
        Node<T> *nodePtr = tail->next;
        for (int count=0;   count<index;    count++)
            nodePtr = nodePtr->next;
        return nodePtr->element;
    }    
    
}




//Empty 
template <class T>
bool CircularList<T>::isEmpty()
{
    if (tail == nullptr)
        return true;
    return false;
}




//Clear
template <class T>
void CircularList<T>::clear()
{
    if (tail)
    {
        Node<T> *nodePtr = tail->next;
        while (nodePtr != tail)
        {
            Node<T> *previousPtr = nodePtr;
            nodePtr = nodePtr->next;
            delete previousPtr;
        }
        delete tail;
        tail = nullptr;
    }
}




//Head Getter
template <class T>
Node<T> *CircularList<T>::getLeader()
{
    return tail->next;
}




//Size Getter
template <class T>
int CircularList<T>::size()const
{
    int size =0;
    if (tail)
    {
        Node<T> *nodePtr = tail->next;
        do
        {
            nodePtr = nodePtr->next;
            size++;
        }
        while (nodePtr != tail->next);
    }
    return size;
}




//Print
template <class T>
ostream &CircularList<T>::print(ostream& os)
{
    os << "[";
    if (tail)
    {
        Node<T> *nodePtr = tail->next;
        do 
        {
            if (nodePtr->next == tail->next)
                os << nodePtr->element;
            else
                os << nodePtr->element << ",";
            nodePtr = nodePtr->next;
        }
        while (nodePtr != tail->next);
    }
    os << "]";
    return os;
}




//Extraction Operator Overload
template <class T>
ostream &operator<<(ostream &os, CircularList<T> &obj)
{
    obj.print(os);
    return os;
}

