#include <iostream>
#include <string>
#include <map>

using namespace std;

int main (int argc, const char **argv)
{
    //Define a phonebook multimap.
   

    //Create a map to hold the seat assignments.
    multimap<string, string> phonebook = 
    {
        {"Will", "444"}, {"Will", "555"},
        {"Faye", "666"}, {"Faye", "777"},
        {"Sarah", "888"}, {"Sarah", "999"},
    };

    
    //Display all objects in the map.
    for (auto element : phonebook){
        cout << element.first << "\t" << element.second << endl;
    }
    return 0;
}