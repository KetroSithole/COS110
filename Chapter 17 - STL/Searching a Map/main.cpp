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

    //Create an iterator.
    map <int, string>:: const_iterator it;

    //Find employee 103.
    it = employee.find(105);

    //Display the employee data.
    if (it != employee.end())
        cout << "ID: " << it->first << "\t\tName: " << it->second << endl;
    else
        cout << "Employee not found\n"; 
    return 0;
}