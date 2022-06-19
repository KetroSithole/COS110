#ifndef PALMVEIN_H
#define PALMVEIN_H

#include "ContactlessDevice.h"

class PalmVein : public ContactlessDevice
{
    protected:
        char hashChar (char);

    public:
        PalmVein (const std::string &, const int &);
        ~PalmVein ();
};
#endif