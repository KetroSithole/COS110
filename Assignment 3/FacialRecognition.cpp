#include "FacialRecognition.h"
#include "Exception.h"


FacialRecognition::FacialRecognition(const std::string &key, const int &maxStudents, int stepSize)
{
    this->setKeyword(key);
    this->maxStudents = maxStudents;
    this->stepSize = stepSize;
    currentStudent = 0;

    array = new int [cols];
    for (int index=0;   index<cols;     index++)
    {
        *(array + index) = *(keyword + index);
    }

    studentDatabase = new std::string *[maxStudents];
    for (int xIndex=0;      xIndex<maxStudents;     xIndex++)
    {
        studentDatabase[xIndex] = new std::string [2];
        for (int yIndex=0;      yIndex<2;       yIndex++)
            studentDatabase[xIndex][yIndex] = 'z';
    }
}


FacialRecognition::~FacialRecognition()
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
    delete array;
}


void FacialRecognition::setStepSize (int size)
{
    if (size < 0)
        throw Exception("Negative number provided");
    else
        stepSize = size;
}


std::string FacialRecognition::registerStudent (const std::string &text)
{
    std::string hashCode = "";
    for (int index=0;    index<text.length();    index++)
    {
        if (index == 0)
        {
            hashCode += hashChar (text[index]);
        }
        else if (index == 1)
        {
            *(keyword) += stepSize;
            this->setRotor();
            hashCode += hashChar (text[index]);
        }
        else if (index > 1)
        {
            *(keyword) += stepSize;
            for (int index=1;   index<cols;     index++)
            {
                *(keyword + index) = rotor[0][index];
            }
            this->setRotor();
            hashCode += hashChar (text[index]);
        }
    }

    for (int index=0;      index<cols;      index++)
    {
        *(keyword + index) = *(array + index);
    }

    for (int index=0;    index<maxStudents;   index++)
    {
        if (currentStudent == maxStudents)
            throw Exception("Student Database is full");
        else if (studentDatabase[index][0] == text)
            throw Exception ("Student already exist");
    }
   
    studentDatabase[currentStudent][0] = text;
    studentDatabase[currentStudent][1] = hashCode;
    currentStudent++;
    return hashCode;
}


std::string FacialRecognition::authenticateStudent (const std::string &text)
{
    std::string hashCode = "";
    for (int index=0;    index<text.length();    index++)
    {
        if (index == 0)
            hashCode += hashChar (text[index]);
        else if (index == 1)
        {
            *(keyword) += stepSize;
            this->setRotor();
            hashCode += hashChar (text[index]);
        }
        else if (index > 1)
        {
            *(keyword) += stepSize;
            for (int index=1;   index<cols;     index++)
            {
                *(keyword + index) = rotor[0][index];
            }
            this->setRotor();
            hashCode += hashChar (text[index]);
        }
    }

    for (int index=0;      index<cols;      index++)
    {
        *(keyword + index) = *(array + index);
    }

    for (int xIndex=0;   xIndex<maxStudents;    xIndex++)
    {
        if (studentDatabase[xIndex][0] == text || studentDatabase[xIndex][1] == hashCode)
            return (hashCode + "true");
    }
    return (hashCode + "false");
}


char FacialRecognition::hashChar (char character)
{
    char hashedChar;
    this->setRotor();
    for (int xIndex=0;      xIndex<10;      xIndex++)
    {
        if (rotor[xIndex][cols-1]+48 == character)
        {
            hashedChar = (xIndex + 48); 
        }
    }
    return hashedChar;
}
