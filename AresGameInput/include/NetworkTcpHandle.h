#ifndef NETWORKTCPHANDLE_H
#define NETWORKTCPHANDLE_H

#include <NetworkHandle.h>


class NetworkTcpHandle : public NetworkHandle
{
    public:
        /** Default constructor */
        NetworkTcpHandle();
        /** Default destructor */
        virtual ~NetworkTcpHandle();

        void SendMessage(int scktFD, string msg);

        string ReadMessage (int scktFD) ;




    protected:

    private:
};

#endif // NETWORKTCPHANDLE_H
