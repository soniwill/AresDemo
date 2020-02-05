#ifndef NETWORKTCPCONTROL_H
#define NETWORKTCPCONTROL_H

#include <NetworkControl.h>
#include <sys/types.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <string>
#include <errno.h>


class NetworkTcpControl : public NetworkControl
{
    public:
        /** Default constructor */
        NetworkTcpControl();
        /** Default destructor */
        virtual ~NetworkTcpControl();

        void Init();
        int DoConnection();
        void Disconnect ();

    protected:

    private:
};

#endif // NETWORKTCPCONTROL_H
