#include <iostream>
#include <iomanip>
#include "PassFailActivity.h"

using namespace std;

//Function prototype
void displayGrade (const GradedActivity &);

/*
****************************************************************************************************
    The displayGrade function displays a GradedActivity object's numeric score and letter grade.   *
****************************************************************************************************
*/

void displayGrade (const GradedActivity &activity){
    cout << fixed <<setprecision(1);
    cout << "The activity's numeric score is " << activity.getScore() << endl;
    cout << "The activity's letter grade is " <<  activity.getLetterGrade() << endl;
}


int main()
{
    //Create a PassFailActivity object. Minimum passing score is 70.
    PassFailActivity test (70);

    //Set the score to 72.
    test.setScore(72);

    /*
    ***********************************************
        Display the object's grade data.          *
        The letter grade should be 'P'.           *
        What will be displayed?                   *
    ***********************************************
    */
   displayGrade (test); 

    return 0;
}