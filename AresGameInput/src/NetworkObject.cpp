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

bool NetworkObject::IsConnected()
{
    return m_connected;
}

void NetworkObject::LoopSentMsgPool()
{
    while(!m_sentMessagesPool.empty())
    {
        m_pNetworkHandle->SendMessage(m_pNetworkControl->newScktFD, m_sentMessagesPool.front());
        m_sentMessagesPool.pop();
    }
}


void NetworkObject::SendMessage(int fd, string msg)
{
    m_pNetworkHandle->SendMessage(fd, msg);
}

void NetworkObject::SendMessage(string msg)
{
    if(m_pNetworkControl->newScktFD <=0 )
        return; //cant send message;

    m_sentMessagesPool.push(msg);
    m_loggerFile.write(msg);
}

std::string NetworkObject::RecvMessage()
{
    std::string newMsg ="";
    if(!m_recvMessagesPool.empty())
    {
        newMsg = m_recvMessagesPool.front();
        m_recvMessagesPool.pop();
        m_loggerFile.write(newMsg);
    }

    return newMsg;
}

void NetworkObject::Debug1(string msg)
{
    m_pNetworkHandle->SendMessage(m_pNetworkControl->newScktFD, msg);
}

void NetworkObject::PopulateRecvMsgPool()
{
    std::string newMsg = m_pNetworkHandle->ReadMessage(m_pNetworkControl->newScktFD);
    m_recvMessagesPool.push(newMsg);
}


void NetworkObject::CloseSckt()
{
    close(m_pNetworkControl->scktFD);
}


