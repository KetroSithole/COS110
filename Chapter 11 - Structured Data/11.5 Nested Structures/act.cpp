//This program uses nested structures.
#include <iostream>
#include <string>

using namespace std;


//The Date structure hold the data about the date
struct Date
{
	int month;
	int day;
	int year;
};


//The Place structure holds a physcical address.
struct Place
{
	string address;
	string city;
	string state;
	string zip;
};


//The EmployeeInfo structure holds an employee's data
struct EmployeeInfo
{
	string name;
	int employeeNumber;
	Date birthDate;				//Nested structure
	Place residence;			//Nested structure
};


int main()
{
	//Define a structure variable to hold info about a manager.
	EmployeeInfo manager;

	//Get the manager's name and employee number.
	cout << "Enter the manager's name: ";
	getline(cin, manager.name);
	cout << "Enter the manager's employee number: ";
	cin >> manager.employeeNumber;

	//Get the manager's birth date.
	cout << "\nNow enter the manager's date of birth:\n";
	cout << "Month (Up to 2 digits): ";
	cin >> manager.birthDate.month;
	cout << "Day (Up to 2 digits): ";
	cin >> manager.birthDate.day;
	cout << "Year: ";
	cin >> manager.birthDate.year;
	cin.ignore();							//Skip the newline character

	//Get the manager's residence information.
	cout << "\nEnter the manager's street address: ";
	getline(cin, manager.residence.address);
	cout << "City: ";
	getline(cin, manager.residence.city);
	cout << "State: ";
	getline(cin, manager.residence.state);
	cout << "Zip: ";
	getline(cin, manager.residence.zip);

	//Display the information just entered.
	cout << "\nHere is the manager's information: \n";
	cout << manager.name << endl;
	cout << manager.employeeNumber << endl;
	cout << manager.birthDate.month << "-" << manager.birthDate.day << "-" << manager.birthDate.year << endl;

	cout << "\nPlace of residence: \n";
	cout << manager.residence.address << endl;
	cout << manager.residence.city << endl;
	cout << manager.residence.state << endl;
	cout << manager.residence.zip << endl;

	return 0;
}