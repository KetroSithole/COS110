//This program demonstrates a simple append operation on a linked list.
#include "NumberList.h"
#include <iostream>

int main (int argc, const char **argv)
{
    //Define a NumberList object.
    NumberList List;

    //Append some values to the list.
    List.appendNode(2.5);
    List.appendNode(7.9);
    List.appendNode(12.65);
    return 0;
}