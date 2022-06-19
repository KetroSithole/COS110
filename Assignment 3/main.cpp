#include <iostream>
#include "PalmVein.h"
#include "FacialRecognition.h"

using namespace std;

int main(int argc, const char *argv[]) {
   
    string s = "456E";
    try { PalmVein palmVein(s, 5); }
    catch (Exception& e) { cout << e.getError(); }

    s = "456";
 
   try {
       PalmVein palmVein(s, 5);
       int* keyWord = palmVein.setKeyword(s);
        for (int i = 0; i < s.length(); i++) {
            cout << keyWord[i];
        }
        cout << endl;
        palmVein.setRotor();

       int** rotor = palmVein.getRotor();
       for (int i = 0; i < 10; i++) {
           for (int j = 0; j < s.length(); j++) {
               cout << rotor[i][j] << " ";
           }
           cout << endl;
       }
       palmVein.registerStudent("7345");
       palmVein.registerStudent("563");
       palmVein.registerStudent("100986");
       palmVein.registerStudent("5335");

       cout << "palmVein.authenticateStudent(5335)" << endl;
       cout << palmVein.authenticateStudent("5335") << endl;

       string** db = palmVein.getStudentDatabase();
       for (int i = 0; i < 5; i++) {
           for (int j = 0; j < 2; j++) {
               cout << db[i][j] << " ";
           }
           cout << endl;
       }
    }
    catch (Exception& e)
    {
        cout << e.getError() << endl;
    }

   
    try {
        FacialRecognition facialRecognition1(s, 5, 34);
        facialRecognition1.setRotor();
        cout << facialRecognition1.registerStudent("7345") << endl;
        cout << facialRecognition1.registerStudent("987") << endl;
        cout << facialRecognition1.authenticateStudent("7345") << endl;
        cout << facialRecognition1.authenticateStudent("987458214") << endl;
    }
    catch (Exception& e)
    {
        cout << e.getError() << endl;
    }

    s = "7894";
    try {
        FacialRecognition facialRecognition1(s, 5, 1);
        facialRecognition1.setRotor();
        cout << facialRecognition1.registerStudent("7345") << endl;
        cout << facialRecognition1.registerStudent("987") << endl;
        cout << facialRecognition1.authenticateStudent("7345") << endl;
        cout << facialRecognition1.authenticateStudent("987458214") << endl;
    }
    catch (Exception& e)
    {
        cout << e.getError() << endl;
    }


    return 0;  
}

/*
 Output
 --------------
456
4 9 5
5 0 6
6 1 7
7 2 8
8 3 9
9 4 0
0 5 1
1 6 2
2 7 3
3 8 4
palmVein.authenticateStudent(5335)
0880true
7345 2890
563 018
100986 655431
5335 0880
z z
2680
 */