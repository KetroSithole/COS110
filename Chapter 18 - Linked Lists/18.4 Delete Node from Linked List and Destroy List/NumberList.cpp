#include "NumberList.h"
#include <cstdlib>

void NumberList::appendNode (double num)
{
    ListNode *newNode;          //To point to a new node.
    ListNode *nodePtr;         //To move through the list.

    //Allocate a new node and store num there.
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = nullptr;

    //If there are no nodes in the list, make newNode the first node.
    if (!head)
        head = newNode;
    else            //Otherwise, insert newNode at the end.
    {
        //Initialize nodePtr to head of the list.
        nodePtr = head;

        //Find the last node in the list.
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        //Insert newNode as the last node.
        nodePtr->next = newNode;
    }
}


void NumberList::displayList () const
{
    ListNode *nodePtr;                                      //To move through the list.

   //Position nodePtr at the head of the list.
    nodePtr = head;

    //While nodePtr points to a node, traverse the list.
    while (nodePtr)
    {
        //Display the values in the node.
        if (nodePtr->next == nullptr)
        {
            std::cout << nodePtr->value << std::endl;
        }
        else        
            std::cout << nodePtr->value << ", ";

        //Move to the next node.
        nodePtr = nodePtr->next;
    }
}


void NumberList::insertNode (double num)
{
    ListNode *newNode;                          //A new node
    ListNode *nodePtr;                          //To traverse the list.
    ListNode *previousNode = nullptr;           //The previous node

    //Allocate a new nodeand store num there.
    newNode = new ListNode;
    newNode->value = num;

    //If there are no nodes in the list, make newNode the first node
    if (!head)
    {
        head = newNode;
        newNode->next = nullptr; 
    }
    else                        //Otherwise, insert newNode
    {
        //Position nodePtr at the head of list.
        nodePtr = head;

        //Initialize the previousNode to nullptr.
        previousNode = nullptr;

        //Skip all nodes whose value is smalller than num.
        while (nodePtr != nullptr && nodePtr->value < num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //If the newNode is to be the 1st in the list, insert it before all other nodes.
        if (previousNode == nullptr)
        {
            head = newNode;
            newNode->next = nodePtr;
        }
        else                            //Otherwue, insert after the previous node.
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}


void NumberList::deleteNode (double num)
{
    ListNode *nodePtr;              //To traverse the list          
    ListNode *previousNode;         //To point to the previous node

    //If the list is empty, do nothing.
    if (!head)
        return;

    //Determine if the first node is the one.
    if (head->value == num)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        //Initialize nodePtr to head of list.
        nodePtr = head;

        //Skip all nodes whose value is not equal to num
        while (nodePtr != nullptr && nodePtr->value != num)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        //If nodePtr is not at the end of the list, link the previous node to the node after nodePtr, then delete nodePtr.
        if (nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}



void NumberList::insert(int index, double element)
{

    ListNode *cur = head;
    ListNode *prev = nullptr;
    ListNode *newNode = new ListNode;

    
    newNode->value = element;

    if (index == 0)
    {
        if (!head)
        {
            newNode->next = nullptr;
            head = newNode;
        }
        else
        {
            newNode->next = head->next;
            head = newNode;
        }
        
    }
  
    else
    {
        ListNode *cur = head;
        ListNode *prev = nullptr;

        for (int count=0;   count<index;      count++)
        {
            prev = cur;
            cur = cur->next;
        }

        prev->next = newNode;
        newNode->next = cur;
    }
   
}
