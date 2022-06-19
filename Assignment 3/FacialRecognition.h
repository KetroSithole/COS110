#ifndef FACIALRECOGNITION_H
#define FACIALRECOGNITION_H
#include "ContactlessDevice.h"

class FacialRecognition : public ContactlessDevice
{
    private:
        int stepSize;
        int *array;
        
    protected:
        char hashChar (char);

    public:
        FacialRecognition(const std::string &, const int &, int stepSize);
        ~FacialRecognition();
        void setStepSize (int);
        std::string registerStudent (const std::string &);
        std::string authenticateStudent (const std::string &);
};
#endif