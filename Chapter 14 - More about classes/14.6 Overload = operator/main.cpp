#include <iostream>
#include "StudentTestScores.h"

using namespace std;

//Function prototype.
void displayStudent (StudentTestScores);

int main(int argc, char const *argv[])
{
	//Create a StudentTestScores object and assign test scores.
	StudentTestScores student1 ("kelly Thorton", 3);
	student1.setTestScore(100.0, 0);
	student1.setTestScore(95.0, 1);
	student1.setTestScore(80, 2);

	//Create another StudentTestScore object with default test scores.
	StudentTestScores student2 ("Jimmy Griffin", 5);

	//Assign the student1 object to student2
	student2 = student1;

	//Display both objects. They should contain the same data.
	displayStudent (student1);
	displayStudent (student2);

	return 0;
}

void displayStudent (StudentTestScores s){
	cout << "Name: " << s.getStudentName() << endl;
	cout << "Test Scores: ";
	for (int count=0;	count<s.getNumTestScores();	 count++){
		cout << s.getTestScore(count) << " ";
	}
	cout << endl;
}
