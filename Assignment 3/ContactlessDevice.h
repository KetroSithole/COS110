#ifndef CONTACTLESSDEVICE_H
#define CONTACTLESSDEVICE_H
#include "AccessDevice.h"

class ContactlessDevice : public AccessDevice
{
    protected:
        int *keyword;
        int maxStudents;
        int currentStudent;
        int **rotor;
        int cols;
        std::string **studentDatabase;
        virtual char hashChar (char) = 0;

    public:
        std::string registerStudent (const std::string &);
        std::string authenticateStudent (const std::string &);
        int *setKeyword (const std::string &);
        void setRotor();
        int **getRotor();
        std::string **getStudentDatabase ();
};
#endif