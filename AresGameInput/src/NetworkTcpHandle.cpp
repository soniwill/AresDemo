#include "NetworkTcpHandle.h"

NetworkTcpHandle::NetworkTcpHandle()
{
    //ctor
}

NetworkTcpHandle::~NetworkTcpHandle()
{
    //dtor
}

void NetworkTcpHandle::SendMessage(int scktFD, string msg)
{
    write(scktFD, msg.c_str(), msg.size());
}

string NetworkTcpHandle::ReadMessage(int scktFD)
{
    memset(buffer,0,256);
    string res ="";
    charLen = read(scktFD,buffer,256);
    if(charLen>0)
    {
        string msg (buffer, charLen);
        res = msg;
    }

    return res;
}
