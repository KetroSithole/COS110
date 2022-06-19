#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>

class Exception
{
    protected:
        std::string error;

    public:
        Exception(const std::string &thrownError){
            error =  thrownError;
        }
        std::string getError(){
            return error;
        }
};
#endif
