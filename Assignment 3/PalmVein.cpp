#include "PalmVein.h"

PalmVein::PalmVein (const std::string &text, const int &maxStd)
{
    maxStudents = maxStd;
    this->setKeyword (text);
    currentStudent = 0;

    studentDatabase = new std::string *[maxStudents];
    for (int xIndex=0;      xIndex<maxStudents;     xIndex++)
    {
        studentDatabase[xIndex] = new std::string [2];
        for (int yIndex=0;      yIndex<2;       yIndex++)
            studentDatabase[xIndex][yIndex] = 'z';
    }
}


char PalmVein::hashChar (char character)
{
    char hashedChar;
    for (int xIndex=0;      xIndex<10;      xIndex++)
    {
        if (rotor[xIndex][cols-1]+48 == character)
            hashedChar = (xIndex + 48);
    }
    return hashedChar;
}


PalmVein::~PalmVein ()
{
    for (int index=0;   index<maxStudents;      index++)
    {
        if (index < 10)
            delete [] rotor[index];

        delete [] studentDatabase[index];
    }
    delete [] rotor;
    delete [] studentDatabase;
    delete keyword;
}