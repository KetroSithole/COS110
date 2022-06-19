#include "ContactlessDevice.h"


std::string ContactlessDevice::registerStudent (const std::string &text)
{
   std::string hashCode = "";
   for (int index=0;    index<text.length();    index++)
      hashCode += hashChar (text[index]);

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


std::string ContactlessDevice::authenticateStudent (const std::string &text)
{
   std::string hashCode = "";
   for (int index=0;    index<text.length();    index++)
      hashCode += hashChar (text[index]);

   for (int xIndex=0;   xIndex<maxStudents;    xIndex++)
   {
      if (studentDatabase[xIndex][0] == text || studentDatabase[xIndex][1] == hashCode)
         return (hashCode + "true");
   }
   return (hashCode + "false");
}


int *ContactlessDevice::setKeyword (const std::string &keyWordText)
{
   if (keyWordText.find_first_not_of("0123456789") == std::string::npos)
   {
      cols = keyWordText.length();
      keyword = new int [cols];
      
      for (int index=0;    index<keyWordText.length();    index++)
         keyword[index]= keyWordText[index] - 48;
   }
   else
      throw Exception ("Invalid input");
   return keyword;
}


void ContactlessDevice::setRotor()
{
   if (keyword == nullptr)
      throw Exception("Keyword must be set");
   else
   {
      rotor = new int *[10];
      for (int xIndex=0;   xIndex<10;      xIndex++)
      {
         int total = 0;
         rotor[xIndex] = new int [cols];
         for (int yIndex=0;  yIndex<cols;   yIndex++)
         {
            total += *(keyword + yIndex);
            if (total>9)
               total -= 10;

            rotor[0][yIndex] = total;
            rotor[xIndex][yIndex] = rotor[0][yIndex]+xIndex;

            while (rotor[xIndex][yIndex]>9)
               rotor[xIndex][yIndex] -= 10;  
         }
      }
   }  
}


int **ContactlessDevice::getRotor()
{
   return rotor;
}


std::string **ContactlessDevice::getStudentDatabase ()
{
   return studentDatabase;
}