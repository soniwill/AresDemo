#include "NetworkTcpControl.h"

NetworkTcpControl::NetworkTcpControl()
{
   Init();
}

NetworkTcpControl::~NetworkTcpControl()
{
    //dtor
}

void NetworkTcpControl::Init()
{
    scktFD = socket(AF_INET, SOCK_STREAM, 0);
    int flags = fcntl(scktFD, F_GETFL);
    fcntl(scktFD, F_SETFL, flags | O_NONBLOCK);
    portNumber = 54003;
    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(portNumber);
    //servAddr.sin_addr.s_addr = INADDR_ANY;
    inet_pton(AF_INET, "0.0.0.0",&servAddr.sin_addr);
    int res = bind(scktFD,(sockaddr*)&servAddr,sizeof(servAddr));
    if(res<0)
    {

       //return;
       //exit(0);
    }

    listen(scktFD, SOMAXCONN);
    addrCliSize = sizeof(cliAddr);
}



int NetworkTcpControl::DoConnection()
{

    newScktFD = accept(scktFD, (sockaddr*)&cliAddr, &addrCliSize);

    //if (newScktFD<0) exit(0);
        //return;
    return newScktFD;

}

void NetworkTcpControl::Disconnect()
{
    close(newScktFD);
    close(scktFD);
}
