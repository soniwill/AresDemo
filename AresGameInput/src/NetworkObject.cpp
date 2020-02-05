#include "NetworkObject.h"

NetworkObject::NetworkObject()
{
    //tcpHandle = new NetworkTcpHandle();
    //tcpControl = new NetworkTcpControl();
    m_connected = false;
    m_pFactory = new NetworkTcpFactory();
    m_pNetworkControl = m_pFactory->GetControl();
    m_pNetworkHandle =  m_pFactory->GetHandle();





    //int socketFD = tcpControl->DoConnection();

//    tcpHandle->SendMessage(socketFD,"Deus eh 10");
//    string msg = tcpHandle->ReadMessage(socketFD);
//    tcpControl->Disconnect();
}

NetworkObject::~NetworkObject()
{
    //dtor
    delete m_pNetworkControl;
    delete m_pNetworkHandle;
    delete m_pFactory;
}

int NetworkObject::DoConnection()
{
    int socketFD;
    socketFD = m_pNetworkControl->DoConnection();
    if(socketFD > 0)
    {
         m_connected = true;
    }
    else
        m_connected = false;

    return socketFD;
}

bool NetworkObject::isConnected()
{
    return m_connected;
}

void NetworkObject::LoopMsgPool()
{
    while(!m_messagesPool.empty())
    {
        m_pNetworkHandle->SendMessage(m_pNetworkControl->newScktFD, m_messagesPool.front());
        m_messagesPool.pop();
    }
}


void NetworkObject::sendMessage(int fd, string msg)
{
    m_pNetworkHandle->SendMessage(fd, msg);
}

void NetworkObject::sendMessage(string msg)
{
    if(m_pNetworkControl->newScktFD <=0 )
        return; //cant send message;

    m_messagesPool.push(msg);
    m_loggerFile.write(msg);
}

void NetworkObject::CloseSckt()
{
    close(m_pNetworkControl->scktFD);
}


