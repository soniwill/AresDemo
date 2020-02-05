#ifndef NETWORKFACTORY_H
#define NETWORKFACTORY_H

#include "NetworkControl.h"
#include "NetworkHandle.h"

class NetworkFactory
{
    public:
        /** Default constructor */
        //NetworkFactory() {}
        /** Default destructor */
        virtual ~NetworkFactory() {}

        //Returns a pointer to a NetworkHandle object

        virtual NetworkHandle *GetHandle () = 0;

        //Returns a pointer to a NetworkControl object

        virtual NetworkControl *GetControl () = 0;

    protected:

    private:

};

#endif // NETWORKFACTORY_H
