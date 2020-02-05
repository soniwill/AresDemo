#ifndef NETWORKHANDLE_H
#define NETWORKHANDLE_H

#include <string.h>
#include <string>

using namespace std;

/*
NetworkHandle is an abstract class which describe a communication handle allowing to send and receive messages
*/


class NetworkHandle
{
    public:
        /** Default constructor */
        //NetworkHandle() {}
        /** Default destructor */
        virtual ~NetworkHandle() {}

        /** Send a message through the socket specified by scktFD
         *
         * scktFD   - socket file descriptor by which the connection was stablished
         * msg      - string that contains a message to be send
         *
         */

        virtual void SendMessage (int scktFD, string msg) = 0;

        /** receives message through the socket specified by scktFD
         *
         * scktFD   - socket file descriptor by which the connection was stablished
         * Return   - Returns a string with a message received through the connection stablished
         *
         */


        virtual string ReadMessage (int scktFD) = 0;

        //The number of characters a function that read or write to the socket returns

        int charLen;

        // buffer which the server store the characters read from the socket

        char buffer[256];

    protected:

    private:
};

#endif // NETWORKHANDLE_H
