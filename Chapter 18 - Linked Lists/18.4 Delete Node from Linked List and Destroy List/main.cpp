//This program demonstrates the deleteNode member function.
#include "NumberList.h"

using namespace std;

int main (int argc, const char **argv)
{
    //Define a NumberList object.
    NumberList List;

    //Build the list with some values.
    List.appendNode(1.1);
    List.appendNode(2.2);
    List.appendNode(3.3);
    List.appendNode(4.4);
    List.appendNode(5.5);
    List.appendNode(6.6);
    List.appendNode(7.7);
    List.appendNode(8.8);
    List.appendNode(9.9);
    

    //Display the list.
    cout << "here are the inital values:\n";
    List.displayList();
    cout << endl;

    List.insert(9, 100.5);

    cout << "here are the values after insert:\n";
    List.displayList();
    cout << endl;
    return 0;
}