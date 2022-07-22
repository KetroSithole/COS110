#include <iostream>
#include <array>

using namespace std;

int main (int argc, const char **argv)
{
    const int SIZE = 4;

    //Store some names in an array object.
    array<string, SIZE> names = {"Ishe", "Kuda", "Joy", "Maria"};

    //Create an iterator for the array object.'
    array<string, SIZE>::iterator it;

    //Display the names.
    cout << "Here are the names:\n";
    for (it = names.begin();    it != names.end();      it++)
        cout << *it << endl;

    return 0;
}