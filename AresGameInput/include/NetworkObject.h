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
        void SendMessage(int fd, string msg);
        void SendMessage(string msg);
        std::string RecvMessage();
        void CloseSckt ();
        bool IsConnected();
        void LoopSentMsgPool();
        void PopulateRecvMsgPool();
        void Debug1(string msg);


    protected:

    private:
         bool m_connected;
         NetworkFactory *m_pFactory;
         NetworkControl *m_pNetworkControl;
         NetworkHandle *m_pNetworkHandle;
         std::queue<string> m_sentMessagesPool;
         std::queue<string> m_recvMessagesPool;
         LoggerFile m_loggerFile;
};

#endif // NETWORKOBJECT_H
