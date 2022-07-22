#include <iostream>
#include <string>
#include <array>

using namespace std;

int main (int argc, const char **argv)
{
    const int SIZE = 4;

    //Store some names in an array object.
    array<string, SIZE> names = {"Ishe", "Kuda", "Joy", "Maria"};

    //Display the names.
    cout << "Here are the names:\n";
    for (auto element : names)
        cout << element << endl;
    cout << endl;


    cout << names.max_size() << endl;

    return 0;
}