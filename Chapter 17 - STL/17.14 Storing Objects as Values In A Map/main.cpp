#include <iostream>
#include <string>
#include <map>
#include "Contact.h"

using namespace std;

int main (int argc, const char **argv)
{
    string searchName;                  //The name to search for.

    //Create some Contact objects
    Contact contact1 ("Ash Mill", "a@gmail.com");
    Contact contact2 ("Jack Ryan", "j@gmail.com");
    Contact contact3 ("Emily Sam", "e@gmail.com");

    //Create a map to hold the Contact objects.
    map <string, Contact> contacts;

    //Create an iterator for the map.
    map<string, Contact>:: iterator it;

    //Add the contact objects to the map.
    contacts[contact1.getName()] = contact1;
    contacts[contact2.getName()] = contact2;
    contacts[contact3.getName()] = contact3;

    //Get the name to search for.
    cout << "Enter a name: ";
    getline(cin, searchName);

    //Search for the name.
    it = contacts.find(searchName);

    //Display the results.
    if (it != contacts.end()){
        cout << "Name: " << it->second.getName() << endl;
        cout << "Email: " << it->second.getEmail() << endl;
    }
    else 
        cout << "Contact not found.\n";
    return 0;
}