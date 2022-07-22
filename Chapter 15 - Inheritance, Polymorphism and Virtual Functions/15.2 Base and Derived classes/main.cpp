//This program demonstrates a base class with a protected member.
#include <iostream>
#include <iomanip>
#include "FinalExam.h"

using namespace std;

int main(int argc, char const *argv[])
{
	int questions;				//Number of questions on the exam.
	int missed;					//Numbe rof questions missed by the student.

	//Get the number of questions on the final exam.
	cout << "How many questions are on the final exam? ";
	cin >> questions;

	//Get the number of questions the student missed.
	cout << "How many questions did the student miss? ";
	cin >> missed;

	//Define a FinalExam object and intialize it with the values entered.
	FinalExam test (questions, missed);

	//Display the results.
	cout << setprecision(3) << fixed;
	cout << "\nEach question counts " << test.getPointsEach() << " points.\n";
	cout << "The adjusted exam score is " << test.getScore() << endl;
	cout << "The exam grade is " << test.getLetterGrade() << endl;

	return 0;
}	