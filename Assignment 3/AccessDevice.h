#ifndef ACCESSDEVICE_H
#define ACCESSDEVICE_H
#include <iostream>
#include "Exception.h"

class AccessDevice
{
    public:
        virtual std::string registerStudent (const std::string &) = 0;
        virtual std::string authenticateStudent (const std::string &) = 0;
};
#endif
