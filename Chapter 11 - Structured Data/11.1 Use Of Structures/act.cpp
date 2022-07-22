//This program demonstrates the use of the structures.
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct PayRoll
{
	int empNumber;				//Employee number
	string name;				//Employe name
	double hours;				//Hours worked
	double payRate;				//Hourly payRate
	double grossPay;			//Gross pay
};


int main()
{
	PayRoll employee;			//employee is a PayRoll structure.

	//Get the employee's number.
	cout << "Enter the employee's number: ";
	cin >> employee.empNumber;

	//Get the employee's name.
	cout << "Enter the employee's name: ";
	cin.ignore();								//To skip the remaininng '\n' character
	getline(cin, employee.name);

	//Get the hours worked by the employee.
	cout << "How many hours did the employee work? ";
	cin >> employee.hours;

	//Get the employee's hourly pay rate.
	cout << "What is the employee's hourly work rate? ";
	cin >> employee.payRate;

	//Calculate the employee's gross pay.
	employee.grossPay = employee.hours * employee.payRate;

	//Display the employee data.
	cout << "\nHere's the employee's payroll data: \n\n";
	cout << "Name: " << employee.name << endl;
	cout << "Number: " << employee.empNumber << endl;
	cout << "Hours worked: " << employee.hours << endl;
	cout << "Hourly pay rate: " << employee.payRate << endl;

	cout << fixed << showpoint << setprecision(2);
	cout << "Gross pay: R" << employee.grossPay << endl;

	return 0;
}