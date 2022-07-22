#include <iostream>
#include "GradeActivity.h"

using namespace std;

int main(int argc, char const *argv[])
{
	double testScore;			//To hold the test score.

	//Create a GradeActivity object for the test.
	GradeActivity test;

	//Get a numeric test score from the user.
	cout << "Enter your numeric test score: ";
	cin >> testScore;

	//Store the numeric socre in the test object.
	test.setScore(testScore);

	//Display the letter grade for the test.
	cout << "The grade for that test is: " << test.getLetterGrade() << endl;

	return 0;
}	