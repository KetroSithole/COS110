#ifndef NUMBERLIST_H
#define NUMBERLIST_H
#include <iostream>

using namespace std;

class NumberList
{
    private:
    
        //Declare a structure for the list.
        struct ListNode
        {
            double value;               //The value in this node.
            struct ListNode *next;      //To point to the next node.
        };

        ListNode *head;                 //List head pointer.
        
    public:

        //Constructor
        NumberList()
        {
            head = nullptr;
        }

        //Destructor()
        ~NumberList()
        {
            ListNode *nodePtr;          //To traverse the list.
            ListNode *nextNode;         //To point to the next node.

            //Position nodePtr at the had of the list.
            nodePtr = head;

            //While nodePtr is not at the end of the list...
            while (nodePtr != nullptr)
            {
                //Save a pointer to the next node.
                nextNode = nodePtr->next;

                //Delete the current node.
                delete nodePtr;

                //Position nodePtr at the end of the next node.
                nodePtr = nextNode;
            }
        }

        //Linked list operations.
        void appendNode (double);
        void insertNode (double);
        void deleteNode (double);
        void displayList () const;
        void shuffle ();
        void insert(int index, double element);

};
#endif
