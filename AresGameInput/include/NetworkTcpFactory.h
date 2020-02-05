#ifndef NETWORKTCPFACTORY_H
#define NETWORKTCPFACTORY_H

#include <NetworkFactory.h>


class NetworkTcpFactory : public NetworkFactory
{
    public:
        /** Default constructor */
        NetworkTcpFactory();
        /** Default destructor */
        virtual ~NetworkTcpFactory();

        //Returns a pointer to a NetworkHandle object

         NetworkHandle *GetHandle ();

        //Returns a pointer to a NetworkControl object

         NetworkControl *GetControl ();


    protected:

    private:
        //NetworkTcpFactory();
};

#endif // NETWORKTCPFACTORY_H
