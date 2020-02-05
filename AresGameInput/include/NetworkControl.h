#ifndef NETWORKCONTROL_H
#define NETWORKCONTROL_H

#include <sys/socket.h>
#include <arpa/inet.h>
/**< NetworkControl is an abstract class which describe communications controls */



class NetworkControl
{
    public:
        /** Default constructor */
        //NetworkControl() {}
        /** Default destructor */
        virtual ~NetworkControl() {}

        /** Initialize the control but doesn't connect it.*/

        virtual void Init () = 0;

        /** \brief Stablish a connection and returns a file descriptor that should be used to send and receive messages
         *
         * \param no parameters
         * \return returns a integer that represents a socket file descriptor that should be used to send and receive messages
         *
         */

        virtual int DoConnection() = 0;

        /** \brief Terminates the connection
         *
         * \param no parameters
         * \return no return value
         *
         */

        virtual void Disconnect () = 0;

        // socket file descriptors

        int scktFD, newScktFD;

        // Port number which the sever accepts connections

        int portNumber;

        //The size of the address of the client.

        socklen_t addrCliSize;

        //contain the address of the server

        sockaddr_in servAddr;

        //contain the address of the client which connects to the server
        sockaddr_in cliAddr;

    protected:

    private:
};

#endif // NETWORKCONTROL_H
