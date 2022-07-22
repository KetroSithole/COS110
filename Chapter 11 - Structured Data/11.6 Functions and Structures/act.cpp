//This program has functions that accept structure variables as arguments.
#include <iostream>
#include <iomanip>

using namespace std;

struct InventoryItem
{
	int partNum;				//Part number
	string description;			//Item description
	int onHand;					//Units on hand
	double price;				//Unit price
};


//Function prototypes
void getItem (InventoryItem&);			//Argument passed by reference
void showItem (const InventoryItem&);			//Argument passed by value


int main()
{
	InventoryItem part;

	getItem (part);
	showItem (part);

	return 0;
}


//****************************************************************************
/*	
	Definition of function getItem. 
	This function uses a structure reference variable as its parameter.
	It asks the user for information to stroe in the structure.
*/
//****************************************************************************


void getItem (InventoryItem &p)						//Uses a reference parameter
{
	//Get the part number.
	cout << "Enter the part number: ";
	cin >> p.partNum;

	//Get the part description.
	cout << "Enter the part description: ";
	cin.ignore();									//Ignore the remaining newline character
	getline(cin, p.description);

	//Get the quantity on hand.
	cout << "Enter the quantity on hand: ";
	cin >> p.onHand;

	//Get the unit price.
	cout << "Enter the unit price: ";
	cin >> p.price;
}


//****************************************************************************************
/*
	Definition of function showItem. 
	This function accepts an argument of the InventoryItem structure type.
	The contents of the structure is displayed.
*/
//****************************************************************************************


void showItem (const InventoryItem &p)
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\nPart Number: " << p.partNum << endl;
	cout << "Description: " << p.description << endl;
	cout << "Units on hand: " << p.onHand << endl;
	cout << "Price: R" << p.price << endl;
}