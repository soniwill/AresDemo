#ifndef NETWORKOBJECT_H
#define NETWORKOBJECT_H

#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>
#include "NetworkFactory.h"
#include "NetworkTcpFactory.h"
#include "NetworkControl.h"
#include "NetworkHandle.h"
#include <queue>
#include "LoggerFile.h"

class NetworkObject
{
    public:
        /** Default constructor */
        NetworkObject();
        /** Default destructor */
        virtual ~NetworkObject();

        int  DoConnection();
        void sendMessage(int fd, string msg);
        void sendMessage(string msg);
        void CloseSckt ();
        bool isConnected();
        void LoopMsgPool();



    protected:

    private:
         bool m_connected;
         NetworkFactory *m_pFactory;
         NetworkControl *m_pNetworkControl;
         NetworkHandle *m_pNetworkHandle;
         std::queue<string> m_messagesPool;
         LoggerFile m_loggerFile;
};

#endif // NETWORKOBJECT_H
