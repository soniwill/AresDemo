#ifndef NETWORKPROTOCOL_H
#define NETWORKPROTOCOL_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

class NetworkProtocol
{
    public:
        int scktFD; // socket file descriptor
        int newScktFD; // socket received after accepting a call
        int portNumber;
        sockaddr_in hint;


        /** Default constructor */
        NetworkProtocol() {}
        /** Default destructor */
        virtual ~NetworkProtocol() {}
        virtual void createSocket () = 0;
        virtual void bindSocket () = 0;


    protected:

    private:
};

#endif // NETWORKPROTOCOL_H
