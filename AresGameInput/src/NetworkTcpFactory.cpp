#include "NetworkTcpFactory.h"
#include "NetworkTcpControl.h"
#include "NetworkTcpHandle.h"



NetworkTcpFactory::NetworkTcpFactory()
{
    //ctor
}

NetworkTcpFactory::~NetworkTcpFactory()
{
    //dtor
}

NetworkHandle* NetworkTcpFactory::GetHandle()
{
    return new NetworkTcpHandle();
}

NetworkControl* NetworkTcpFactory::GetControl()
{
    return new NetworkTcpControl();
}
