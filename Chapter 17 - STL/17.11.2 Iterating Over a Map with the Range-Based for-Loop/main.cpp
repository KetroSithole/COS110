//This program demonstrates an iterator with a map.
#include <iostream>
#include <map>

using namespace std;

int main (int argc, const char **argv)
{
    //Create a map containing employee IDs and names.'
    map <int, string> employee = 
    {
        {101, "Chris Rock"},
        {102, "Jessica Cruz"},
        {103, "Amanda Stevens"},
        {104, "Will Smith"}
    };

    //Use the Range-Based for Loop to display each element in the map.
    for (pair<int, string> element : employee)
        cout << "ID: " << element.first << "\t\tName: " << element.second << endl;

    return 0;
}