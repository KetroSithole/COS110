//This program demonstrates the insertNode member function.
#include "NumberList.h"

int main (int argc, const char **argv)
{
    //Define a NumberList object.
    NumberList List;

    //Append some values to the list.
    List.appendNode(2.5);
    List.appendNode(7.9);
    List.appendNode(12.65);

    //Insert a node in the middle of the list
    List.insertNode (10.5);

    //Display the values in the list.
    List.displayList ();
    return 0;
}