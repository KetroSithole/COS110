#include "SimpleVector.h"
#include "SimpleVector.cpp"

int main (int argc, const char **argv)
{
    const int SIZE = 10;                        //# of elements
    int index;                                  //Loop counter

    //Create a SimpleVector of ints.
    SimpleVector<int> intTable (SIZE);


    //Create a SimpleVector of doubles.
    SimpleVector<double> doubleTable (SIZE);


    //Store values in the two SimpleVectors.
    for (index = 0;     index < SIZE;   index++){
        intTable[index] = (index * 2);
        doubleTable[index] = (index * 2.14);
    }


    //Display the values in the SimpleVectors.
    cout << "These values are in intTable:\n\n";
    for (index = 0;     index < SIZE;   index++)
        cout << intTable[index] << " ";
    cout << endl;

    cout << "\nThese are the values in doubleTable:\n\n";
    for (index = 0;     index < SIZE;   index++)
        cout << doubleTable[index] << " ";
    cout << endl;


    //Use the standard + operator on the elements.
    cout << "\nAdding 5 to each element of intTable and doubleTable.\n";
    for (index = 0;     index < SIZE;   index++){
        intTable[index] = intTable[index] + 5;
        doubleTable[index] = doubleTable[index] + 5;
    }


    //Display the values in the SimpleVectors.
    cout << "\nThese values are in intTable:\n";
    for (index = 0;     index < SIZE;   index++)
        cout << intTable[index] << " ";
    cout << endl;

    cout << "\nThese values are in doubletTable:\n";
    for (index = 0;     index < SIZE;   index++)
        cout << doubleTable[index] << " ";
    cout << endl;


    //Use the standard ++operator on the elements.
    cout << "\nIncrementing each element of intTable and doubleTable.\n";
    cout << "\nThese values are in intTable:\n";
    for (index = 0;     index < SIZE;   index++){
        intTable[index]++;
        doubleTable[index]++;
    }


    //Display the values in the values in the SimpleVectors.
    cout << "\nThese values are in intTable:\n";
    for (index = 0;     index < SIZE;   index++)
        cout << intTable[index] << " ";
    cout << endl;

    cout << "\nThese values are in doubletTable:\n";
    for (index = 0;     index < SIZE;   index++)
        cout << doubleTable[index] << " ";
    cout << endl; 

    return 0;
}