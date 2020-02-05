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
    write(scktFD, msg.c_str(), 256);
}

string NetworkTcpHandle::ReadMessage(int scktFD)
{
    memset(buffer,0,256);
    charLen = read(scktFD,buffer,256);

    string msg (buffer, 256);


    return msg;
}
