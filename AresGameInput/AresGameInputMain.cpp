/***************************************************************
 * Name:      AresGameInputMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Willian Jefferson (willianjefferson7@gmail.com)
 * Created:   2020-01-29
 * Copyright: Willian Jefferson ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "AresGameInputMain.h"
#include <wx/msgdlg.h>
#include <iostream>
#include <sstream>
#include <string>

template < typename Type > std::string to_str (const Type & t)
{
  std::ostringstream os;
  os << t;
  return os.str ();
}


//(*InternalHeaders(AresGameInputFrame)
#include <wx/string.h>
#include <wx/intl.h>
#include <wx/bitmap.h>
#include <wx/image.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(AresGameInputFrame)
const long AresGameInputFrame::ID_BITMAPBUTTON1 = wxNewId();
const long AresGameInputFrame::ID_BITMAPBUTTON4 = wxNewId();
const long AresGameInputFrame::ID_BITMAPBUTTON2 = wxNewId();
const long AresGameInputFrame::ID_BITMAPBUTTON3 = wxNewId();
const long AresGameInputFrame::ID_BITMAPBUTTON5 = wxNewId();
const long AresGameInputFrame::ID_PANEL3 = wxNewId();
const long AresGameInputFrame::ID_SLIDER1 = wxNewId();
const long AresGameInputFrame::ID_STATICLINE1 = wxNewId();
const long AresGameInputFrame::ID_SLIDER2 = wxNewId();
const long AresGameInputFrame::ID_STATICLINE2 = wxNewId();
const long AresGameInputFrame::ID_BITMAPBUTTON6 = wxNewId();
const long AresGameInputFrame::ID_PANEL2 = wxNewId();
const long AresGameInputFrame::ID_PANEL1 = wxNewId();
const long AresGameInputFrame::idMenuQuit = wxNewId();
const long AresGameInputFrame::idMenuAbout = wxNewId();
const long AresGameInputFrame::ID_STATUSBAR1 = wxNewId();
//*)



BEGIN_EVENT_TABLE(AresGameInputFrame,wxFrame)
    //(*EventTable(AresGameInputFrame)
    //*)
    EVT_CLOSE(AresGameInputFrame::OnClose)
    //EVT_WINDOW_CREATE(AresGameInputFrame::DoStartThread)

END_EVENT_TABLE()



AresGameInputFrame::AresGameInputFrame(wxWindow* parent,wxWindowID id)
{
//    NetworkTcpHandle *tcpHandle = new NetworkTcpHandle();
//    NetworkTcpControl *tcpControl = new NetworkTcpControl();
//    int fd =tcpControl->DoConnection();
//    tcpHandle->SendMessage(fd,"Deus é 10");
//    tcpControl->Disconnect();

    //(*Initialize(AresGameInputFrame)
    wxMenuItem* MenuItem2;
    wxStaticBoxSizer* StaticBoxSizer2;
    wxMenuItem* MenuItem1;
    wxGridSizer* GridSizer1;
    wxMenu* Menu1;
    wxGridSizer* GridSizer2;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    wxFrame::Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(869,464));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,40), wxSize(869,500), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel2 = new wxPanel(Panel1, ID_PANEL3, wxPoint(20,20), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL3"));
    StaticBoxSizer1 = new wxStaticBoxSizer(wxHORIZONTAL, Panel2, _("Movement Controls"));
    GridSizer1 = new wxGridSizer(3, 3, 0, 0);
    GridSizer1->Add(27,14,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton1 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON1, wxBitmap(wxImage(_T("/home/willian/src/AresGameInput/images/up.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON1"));
    GridSizer1->Add(BitmapButton1, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    GridSizer1->Add(32,16,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton4 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON4, wxBitmap(wxImage(_T("/home/willian/src/AresGameInput/images/left.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON4"));
    GridSizer1->Add(BitmapButton4, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BitmapButton2 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON2, wxBitmap(wxImage(_T("/home/willian/src/AresGameInput/images/center.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON2"));
    BitmapButton2->Disable();
    GridSizer1->Add(BitmapButton2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    BitmapButton3 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON3, wxBitmap(wxImage(_T("/home/willian/src/AresGameInput/images/right.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON3"));
    GridSizer1->Add(BitmapButton3, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    GridSizer1->Add(35,17,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton5 = new wxBitmapButton(Panel2, ID_BITMAPBUTTON5, wxBitmap(wxImage(_T("/home/willian/src/AresGameInput/images/down.png"))), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON5"));
    GridSizer1->Add(BitmapButton5, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    GridSizer1->Add(24,26,1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer1->Add(GridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel2->SetSizer(StaticBoxSizer1);
    StaticBoxSizer1->Fit(Panel2);
    StaticBoxSizer1->SetSizeHints(Panel2);
    Panel3 = new wxPanel(Panel1, ID_PANEL2, wxPoint(300,20), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    StaticBoxSizer2 = new wxStaticBoxSizer(wxHORIZONTAL, Panel3, _("Weapon Controls"));
    GridSizer2 = new wxGridSizer(0, 5, 0, 0);
    Slider1 = new wxSlider(Panel3, ID_SLIDER1, 0, -10, 60, wxDefaultPosition, wxSize(100,130), wxSL_VERTICAL|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
    GridSizer2->Add(Slider1, 1, wxLEFT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine1 = new wxStaticLine(Panel3, ID_STATICLINE1, wxDefaultPosition, wxSize(10,248), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    GridSizer2->Add(StaticLine1, 1, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Slider2 = new wxSlider(Panel3, ID_SLIDER2, 0, -180, 180, wxDefaultPosition, wxSize(100,-1), wxSL_HORIZONTAL|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER2"));
    GridSizer2->Add(Slider2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticLine2 = new wxStaticLine(Panel3, ID_STATICLINE2, wxDefaultPosition, wxSize(10,248), wxLI_VERTICAL, _T("ID_STATICLINE2"));
    GridSizer2->Add(StaticLine2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    BitmapButton6 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    GridSizer2->Add(BitmapButton6, 1, wxALL|wxALIGN_LEFT|wxALIGN_CENTER_VERTICAL, 0);
    StaticBoxSizer2->Add(GridSizer2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(StaticBoxSizer2);
    StaticBoxSizer2->Fit(Panel3);
    StaticBoxSizer2->SetSizeHints(Panel3);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);

    Connect(ID_BITMAPBUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton1Click1);
    Connect(ID_BITMAPBUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton4Click);
    Connect(ID_BITMAPBUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton3Click);
    Connect(ID_BITMAPBUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton5Click);
    Connect(ID_SLIDER1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&AresGameInputFrame::OnSlider1CmdScroll);
    Connect(ID_SLIDER2,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&AresGameInputFrame::OnSlider2CmdScroll);
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton6Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AresGameInputFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&AresGameInputFrame::OnAbout);
    //*)


    Bind(wxEVT_COMMAND_NETWORKTHREAD_UPDATE, &AresGameInputFrame::OnThreadUpdate, this);
    Bind(wxEVT_COMMAND_NETWORKTHREAD_COMPLETED, &AresGameInputFrame::OnThreadCompletion, this);
    //Bind(wxEVT_ENTER_WINDOW, &AresGameInputFrame::start, this);

    front   = 50.0f;
    back    = 50.0f;
    right   = 50.0f;
    left    = 50.0f;
    frontBackValue  = 0.0f;
    rightLeftValue  = 0.0f;
    step  = 1.0f;
    m_obj = new NetworkObject();
    start();
}

AresGameInputFrame::AresGameInputFrame()
{

}

AresGameInputFrame::~AresGameInputFrame()
{
    //(*Destroy(AresGameInputFrame)
    //*)
    delete m_obj;
}

wxThread::ExitCode AresGameInputFrame::Entry()
{

    while (!GetThread()->TestDestroy())
    {
        int socketFD ;
        if(!m_obj->isConnected())
        {
            socketFD = m_obj->DoConnection();
        }

        if (socketFD == -1)
        {

        }
        else
        {
            m_obj->LoopMsgPool();
            //obj.CloseSckt();
            wxThread::This()->Sleep(100);
        }

    }

    return (wxThread::ExitCode)0;     // success
}

void AresGameInputFrame::DoStartThread(wxWindowCreateEvent& event)
{
    //start();
//    m_pThread = new NetworkThread(this);
//    if ( m_pThread->Run() != wxTHREAD_NO_ERROR )
//    {
//        wxLogError("Can't create the thread!");
//        delete m_pThread;
//        m_pThread = NULL;
//    }
    // after the call to wxThread::Run(), the m_pThread pointer is "unsafe":
    // at any moment the thread may cease to exist (because it completes its work).
    // To avoid dangling pointers OnThreadExit() will set m_pThread
    // to NULL when the thread dies.
}

void AresGameInputFrame::OnThreadCompletion(wxThreadEvent& event)
{
    wxMessageOutputDebug().Printf("AresGameInputFrame: NetworkThread exited!\n");
}
void AresGameInputFrame::OnThreadUpdate(wxThreadEvent& event)
{
    wxMessageOutputDebug().Printf("AresGameInputFrame: NetworkThread update...\n");
}

void AresGameInputFrame::DoPauseThread()
{
    // anytime we access the m_pThread pointer we must ensure that it won't
    // be modified in the meanwhile; since only a single thread may be
    // inside a given critical section at a given time, the following code
    // is safe:
//    wxCriticalSectionLocker enter(m_pThreadCS);
//    if (m_pThread)         // does the thread still exist?
//    {
//        // without a critical section, once reached this point it may happen
//        // that the OS scheduler gives control to the MyThread::Entry() function,
//        // which in turn may return (because it completes its work) making
//        // invalid the m_pThread pointer
//        if (m_pThread->Pause() != wxTHREAD_NO_ERROR )
//            wxLogError("Can't pause the thread!");
//    }
}
void AresGameInputFrame::OnClose(wxCloseEvent& event)
{
    if (GetThread() &&      // DoStartALongTask() may have not been called
        GetThread()->IsRunning())
        GetThread()->Delete();
    Destroy();
//    {
//        wxCriticalSectionLocker enter(m_pThreadCS);
//        if (m_pThread)         // does the thread still exist?
//        {
//            m_pThread->closeCliFD();
//            wxMessageOutputDebug().Printf("AresGameInputFrame: deleting thread");
//            if (m_pThread->Delete() != wxTHREAD_NO_ERROR )
//                wxLogError("Can't delete the thread!");
//        }
//    }       // exit from the critical section to give the thread
//            // the possibility to enter its destructor
//            // (which is guarded with m_pThreadCS critical section!)
//    while (1)
//    {
//        { // was the ~MyThread() function executed?
//            wxCriticalSectionLocker enter(m_pThreadCS);
//            if (!m_pThread) break;
//        }
//        // wait for thread completion
//        wxThread::This()->Sleep(100);
//    }
//    Destroy();
}

void AresGameInputFrame::start()
{
    if (CreateThread(wxTHREAD_DETACHED) != wxTHREAD_NO_ERROR)
    {
        wxLogError("Could not create the worker thread!");
        return;
    }
    // go!
    if (GetThread()->Run() != wxTHREAD_NO_ERROR)
    {
         wxLogError("Could not run the worker thread!");
        return;
    }
}

int AresGameInputFrame::teste()
{
    return 1;
}

void AresGameInputFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void AresGameInputFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void AresGameInputFrame::OnBitmapButton1Click1(wxCommandEvent& event)
{
    front = front + step;
    back = back - step;
    front = std::clamp(front,0.0f,100.0f);
    back = std::clamp(back,0.0f,100.0f);
    m_obj->sendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(front) + ";" + to_str(back) + ";" + to_str(left) + ";" + to_str(right));
}

void AresGameInputFrame::OnBitmapButton5Click(wxCommandEvent& event)
{
    front = front - step;
    back = back + step;
    front = std::clamp(front,0.0f,100.0f);
    back = std::clamp(back,0.0f,100.0f);
    m_obj->sendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(front) + ";" + to_str(back) + ";" + to_str(left) + ";" + to_str(right));
}

void AresGameInputFrame::OnBitmapButton4Click(wxCommandEvent& event)
{
    left = left + step;
    right = right - step;
    left = std::clamp(left,0.0f,100.0f);
    right = std::clamp(right,0.0f,100.0f);
    m_obj->sendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(front) + ";" + to_str(back) + ";" + to_str(left) + ";" + to_str(right));
}

void AresGameInputFrame::OnBitmapButton3Click(wxCommandEvent& event)
{
    left = left - step;
    right = right + step;
    left = std::clamp(left,0.0f,100.0f);
    right = std::clamp(right,0.0f,100.0f);
    m_obj->sendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(front) + ";" + to_str(back) + ";" + to_str(left) + ";" + to_str(right));
}

void AresGameInputFrame::OnSlider1CmdScroll(wxScrollEvent& event)
{
    int pos = event.GetPosition();
    m_obj->sendMessage(NetworkMessages::WEAPON_ELEVATION + ";" + to_str(pos));
}

void AresGameInputFrame::OnSlider2CmdScroll(wxScrollEvent& event)
{
    int pos = event.GetPosition();
    m_obj->sendMessage(NetworkMessages::WEAPON_ROTATION + ";" + to_str(pos));
}

void AresGameInputFrame::OnBitmapButton6Click(wxCommandEvent& event)
{
    m_obj->sendMessage(NetworkMessages::FIRE_WEAPON);
}