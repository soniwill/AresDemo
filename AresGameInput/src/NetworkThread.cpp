#include "NetworkThread.h"
#include "NetworkObject.h"


wxDEFINE_EVENT(wxEVT_COMMAND_NETWORKTHREAD_COMPLETED, wxThreadEvent);
wxDEFINE_EVENT(wxEVT_COMMAND_NETWORKTHREAD_UPDATE, wxThreadEvent);

NetworkThread::NetworkThread(AresGameInputFrame *handler) : wxThread(wxTHREAD_DETACHED)
{
    m_pHandler = handler;
}

NetworkThread::~NetworkThread()
{
   // wxCriticalSectionLocker enter(m_pHandler->m_pThreadCS);
    // the thread is being destroyed; make sure not to leave dangling pointers around
    //m_pHandler->m_pThread = NULL;
}

wxThread::ExitCode NetworkThread::Entry()
{

    NetworkObject obj;


    while (!TestDestroy())
    {
        int socketFD ;
        if(!obj.IsConnected())
        {
            socketFD = obj.DoConnection();
        }

        cliFD = socketFD;
        //auto event = new wxThreadEvent(wxEVT_COMMAND_NETWORKTHREAD_UPDATE);

        // ENCAPSULAR TUDO ISSO DENTRO DA CLASSE NETWORKOBJECT

        if (socketFD == -1)
        {
//            if (errno == EWOULDBLOCK)
//            {
//                wxMessageOutputDebug().Printf("No pending connections; sleeping for one second.\n");
//                //wxThread::This()->Sleep(1000);
//            }
//            else
//            {
//                wxLogError("error when accepting connection");
//                exit(1);
//            }
        }
        else
        {
            //obj.CloseSckt();
            obj.SendMessage(socketFD,"Deus é 10");
            wxThread::This()->Sleep(100);
        }

        // ... do a bit of work...
        //this->Sleep(1);
        //wxQueueEvent(m_pHandler, event);
    }
    //obj.CloseSckt();
    // signal the event handler that this thread is going to be destroyed
    // NOTE: here we assume that using the m_pHandler pointer is safe,
    //       (in this case this is assured by the MyFrame destructor)
    //wxQueueEvent(m_pHandler, new wxThreadEvent(wxEVT_COMMAND_NETWORKTHREAD_COMPLETED));
    return (wxThread::ExitCode)0;     // success
}
void NetworkThread::closeCliFD()
{
    close(cliFD);
}

