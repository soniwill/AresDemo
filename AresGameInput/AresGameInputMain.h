/***************************************************************
 * Name:      AresGameInputMain.h
 * Purpose:   Defines Application Frame
 * Author:    Willian Jefferson (willianjefferson7@gmail.com)
 * Created:   2020-01-29
 * Copyright: Willian Jefferson ()
 * License:
 **************************************************************/

#ifndef ARESGAMEINPUTMAIN_H
#define ARESGAMEINPUTMAIN_H



//(*Headers(AresGameInputFrame)
#include <wx/bmpbuttn.h>
#include <wx/sizer.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/slider.h>
#include <wx/statusbr.h>
#include <wx/statline.h>
#include <wx/frame.h>
//*)
#include "include/NetworkThread.h"
#include "include/NetworkTcpControl.h"
#include "include/NetworkTcpHandle.h"
#include <algorithm>
#include "include/NetworkObject.h"
#include "include/NetworkMessages.h"



//class NetworkThread;

class AresGameInputFrame: public wxFrame, public wxThreadHelper
{
    public:

        AresGameInputFrame(wxWindow* parent,wxWindowID id = -1);
        AresGameInputFrame();
        virtual ~AresGameInputFrame();
        int teste();
        void DoStartThread(wxWindowCreateEvent& event);
        void DoPauseThread();
        void OnThreadCompletion(wxThreadEvent&);
        void OnThreadUpdate(wxThreadEvent&);

        void OnClose(wxCloseEvent&);

    private:

        //(*Handlers(AresGameInputFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnBitmapButton1Click(wxCommandEvent& event);
        void OnPanel1Paint(wxPaintEvent& event);
        void OnBitmapButton1Click1(wxCommandEvent& event);
        void OnBitmapButton5Click(wxCommandEvent& event);
        void OnBitmapButton4Click(wxCommandEvent& event);
        void OnBitmapButton3Click(wxCommandEvent& event);
        void OnSlider1CmdScroll(wxScrollEvent& event);
        void OnSlider2CmdScroll(wxScrollEvent& event);
        void OnBitmapButton6Click(wxCommandEvent& event);
        //*)

        float front, back, right, left, frontBackValue, rightLeftValue, step;



        void start();

        //(*Identifiers(AresGameInputFrame)
        static const long ID_BITMAPBUTTON1;
        static const long ID_BITMAPBUTTON4;
        static const long ID_BITMAPBUTTON2;
        static const long ID_BITMAPBUTTON3;
        static const long ID_BITMAPBUTTON5;
        static const long ID_PANEL3;
        static const long ID_SLIDER1;
        static const long ID_STATICLINE1;
        static const long ID_SLIDER2;
        static const long ID_STATICLINE2;
        static const long ID_BITMAPBUTTON6;
        static const long ID_PANEL2;
        static const long ID_PANEL1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(AresGameInputFrame)
        wxBitmapButton* BitmapButton2;
        wxPanel* Panel1;
        wxBitmapButton* BitmapButton3;
        wxStaticLine* StaticLine2;
        wxStatusBar* StatusBar1;
        wxPanel* Panel2;
        wxStaticLine* StaticLine1;
        wxBitmapButton* BitmapButton5;
        wxBitmapButton* BitmapButton4;
        wxPanel* Panel3;
        wxSlider* Slider2;
        wxSlider* Slider1;
        wxBitmapButton* BitmapButton1;
        wxBitmapButton* BitmapButton6;
        //*)

    protected:
        virtual wxThread::ExitCode Entry();
        //NetworkThread *m_pThread;
        NetworkObject *m_obj;
        wxCriticalSection m_objCS; // protects the m_pThread pointer
        wxThread *threadTest;

        //friend class NetworkThread;     // allow it to access the m_pThread

        DECLARE_EVENT_TABLE()
};

#endif // ARESGAMEINPUTMAIN_H
