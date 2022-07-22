#include <iostream>
#include <string>
#include <iomanip>

using namespace std; 

struct Student
{
	string name;			//Student name
	int IdNum;				//Student ID Number
	int creditHours;		//Credit hours enrolled
	double gpa;				//Current GPA

};


//Function prototype
void getData (Student *);


//********************************************************************************
/*
	Definition of function getData.
	Uses a pointer to a Student structure variable.
	The user enters student information, which is stored in the variable.
*/
//********************************************************************************


void getData (Student *s)
{
	//Get the student name
	cout << "1. Student name: ";
	getline (cin, s->name);

	//Get the student ID number
	cout << "2. Student ID number: ";
	cin >> s->IdNum;

	//Get the credit hours enrolled.
	cout << "3. Credit Hours Enrolled: ";
	cin >> s->creditHours;

	//Get the GPA
	cout << "4. Current GPA: ";
	cin >> s->gpa;
}


int main(int argc, char const *argv[])
{
	Student freshman;

	//Get the student data.
	cout << "Enter the following student data: \n";
	getData (&freshman);			//PAss the adddress of freshman

	cout << "\nHere is the student data you entered: \n";

	//Now display the data stored in freshman
	cout << setprecision(3);
	cout << "Name: " << freshman.name << endl;
	cout << "ID Number: " << freshman.IdNum << endl;
	cout << "Credit Hours: " << freshman.creditHours << endl;
	cout << "GPA: " << freshman.gpa << endl;

	return 0;
}