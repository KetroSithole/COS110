#include "NumberList.h"

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
        std::cout << nodePtr->value << std::endl;

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


