#ifndef NETWORKTHREAD_H
#define NETWORKTHREAD_H

#include <wx/thread.h>
#include "../AresGameInputMain.h"
#include <assert.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <queue>
#include <map>
#include <cctype>

#include <steam/steamnetworkingsockets.h>
#include <steam/isteamnetworkingutils.h>
#ifndef STEAMNETWORKINGSOCKETS_OPENSOURCE
#include <steam/steam_api.h>
#endif

#ifdef WIN32
	#include <windows.h> // Ug, for NukeProcess -- see below
#else
	#include <unistd.h>
	#include <signal.h>
#endif

wxDECLARE_EVENT(wxEVT_COMMAND_NETWORKTHREAD_COMPLETED, wxThreadEvent);
wxDECLARE_EVENT(wxEVT_COMMAND_NETWORKTHREAD_UPDATE, wxThreadEvent);

class AresGameInputFrame;

class NetworkThread : public wxThread
{
    public:
        /** Default constructor */
        NetworkThread(AresGameInputFrame *handler);
        /** Default destructor */
        virtual ~NetworkThread();
        void closeCliFD();


    protected:
        virtual ExitCode Entry();

        AresGameInputFrame *m_pHandler;

    private:
        int cliFD;
};

#endif // NETWORKTHREAD_H
