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
const long AresGameInputFrame::ID_STATICTEXT1 = wxNewId();
const long AresGameInputFrame::ID_TEXTCTRL1 = wxNewId();
const long AresGameInputFrame::ID_BUTTON1 = wxNewId();
const long AresGameInputFrame::ID_PANEL4 = wxNewId();
const long AresGameInputFrame::ID_STATICTEXT2 = wxNewId();
const long AresGameInputFrame::ID_TEXTCTRL2 = wxNewId();
const long AresGameInputFrame::ID_BUTTON2 = wxNewId();
const long AresGameInputFrame::ID_PANEL5 = wxNewId();
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
    wxFlexGridSizer* FlexGridSizer1;
    wxMenu* Menu1;
    wxGridSizer* GridSizer4;
    wxGridSizer* GridSizer3;
    wxGridSizer* GridSizer6;
    wxStaticBoxSizer* StaticBoxSizer3;
    wxGridSizer* GridSizer5;
    wxStaticBoxSizer* StaticBoxSizer4;
    wxMenuBar* MenuBar1;
    wxMenu* Menu2;
    wxStaticBoxSizer* StaticBoxSizer1;

    wxFrame::Create(parent, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(869,550));
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(0,40), wxSize(869,540), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
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
    FlexGridSizer1 = new wxFlexGridSizer(0, 5, 0, 0);
    Slider1 = new wxSlider(Panel3, ID_SLIDER1, 0, -10, 60, wxDefaultPosition, wxSize(100,257), wxSL_VERTICAL|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER1"));
    FlexGridSizer1->Add(Slider1, 1, wxBOTTOM|wxEXPAND, 1);
    StaticLine1 = new wxStaticLine(Panel3, ID_STATICLINE1, wxDefaultPosition, wxSize(10,248), wxLI_VERTICAL, _T("ID_STATICLINE1"));
    FlexGridSizer1->Add(StaticLine1, 1, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 25);
    Slider2 = new wxSlider(Panel3, ID_SLIDER2, 0, -180, 180, wxDefaultPosition, wxSize(242,73), wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS, wxDefaultValidator, _T("ID_SLIDER2"));
    FlexGridSizer1->Add(Slider2, 0, wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 0);
    StaticLine2 = new wxStaticLine(Panel3, ID_STATICLINE2, wxDefaultPosition, wxSize(10,248), wxLI_VERTICAL, _T("ID_STATICLINE2"));
    FlexGridSizer1->Add(StaticLine2, 0, wxLEFT|wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 25);
    BitmapButton6 = new wxBitmapButton(Panel3, ID_BITMAPBUTTON6, wxNullBitmap, wxDefaultPosition, wxSize(50,50), wxBU_AUTODRAW, wxDefaultValidator, _T("ID_BITMAPBUTTON6"));
    FlexGridSizer1->Add(BitmapButton6, 0, wxRIGHT|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 25);
    StaticBoxSizer2->Add(FlexGridSizer1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel3->SetSizer(StaticBoxSizer2);
    StaticBoxSizer2->Fit(Panel3);
    StaticBoxSizer2->SetSizeHints(Panel3);
    Panel4 = new wxPanel(Panel1, ID_PANEL4, wxPoint(24,328), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL4"));
    StaticBoxSizer3 = new wxStaticBoxSizer(wxHORIZONTAL, Panel4, _("Server Controls"));
    GridSizer4 = new wxGridSizer(2, 1, 0, 0);
    GridSizer3 = new wxGridSizer(0, 2, 0, 0);
    StaticText1 = new wxStaticText(Panel4, ID_STATICTEXT1, _("Listening Port:"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    GridSizer3->Add(StaticText1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl1 = new wxTextCtrl(Panel4, ID_TEXTCTRL1, _("54003"), wxDefaultPosition, wxSize(67,27), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    GridSizer3->Add(TextCtrl1, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer4->Add(GridSizer3, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button1 = new wxButton(Panel4, ID_BUTTON1, _("Start Demo"), wxDefaultPosition, wxSize(187,29), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button1->Disable();
    GridSizer4->Add(Button1, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer3->Add(GridSizer4, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel4->SetSizer(StaticBoxSizer3);
    StaticBoxSizer3->Fit(Panel4);
    StaticBoxSizer3->SetSizeHints(Panel4);
    Panel5 = new wxPanel(Panel1, ID_PANEL5, wxPoint(400,310), wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL5"));
    Panel5->Hide();
    StaticBoxSizer4 = new wxStaticBoxSizer(wxHORIZONTAL, Panel5, _("Label"));
    GridSizer5 = new wxGridSizer(2, 1, 0, 0);
    GridSizer6 = new wxGridSizer(0, 2, 0, 0);
    StaticText2 = new wxStaticText(Panel5, ID_STATICTEXT2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    GridSizer6->Add(StaticText2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    TextCtrl2 = new wxTextCtrl(Panel5, ID_TEXTCTRL2, _("Text"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    GridSizer6->Add(TextCtrl2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    GridSizer5->Add(GridSizer6, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel5, ID_BUTTON2, _("Label"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    GridSizer5->Add(Button2, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    StaticBoxSizer4->Add(GridSizer5, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel5->SetSizer(StaticBoxSizer4);
    StaticBoxSizer4->Fit(Panel5);
    StaticBoxSizer4->SetSizeHints(Panel5);
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
    Connect(ID_BITMAPBUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnBitmapButton6Click);
    Connect(ID_SLIDER1,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&AresGameInputFrame::OnSlider1CmdScroll);
    Connect(ID_SLIDER2,wxEVT_SCROLL_THUMBTRACK,(wxObjectEventFunction)&AresGameInputFrame::OnSlider2CmdScroll);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&AresGameInputFrame::OnButton1Click);
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

    m_zAxis = 0.0f;
    m_xAxis = 0.0f;

    m_step  = 0.1f;
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
    std::thread receiveMsgsThread(&AresGameInputFrame::ProcessMessages, this);
    while (!GetThread()->TestDestroy())
    {
        int socketFD ;
        if(!m_obj->IsConnected())
        {
            socketFD = m_obj->DoConnection();
        }

        if (socketFD == -1)
        {

        }
        else
        {
            m_obj->PopulateRecvMsgPool();
            m_obj->LoopSentMsgPool();
            //m_obj->Debug1("Execução de teste");
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

void AresGameInputFrame::ProcessMessages()
{
    while(true)
    {
        std::string msg;
        if(m_obj && m_obj->IsConnected())
        {
            msg = m_obj->RecvMessage();
            const std::vector<std::string> strings = Util::explode(msg,';');
            if(strings.empty()) continue;

            if(strings[0]== NetworkMessages::CLIENT_READY)
            {
                Button1->Enable(true);
            }
            else if (strings[0]== NetworkMessages::CLIENT_DISCONNECTED)
            {
                m_obj->Disconnect();
                Button1->Enable(false);
            }
            else if (strings[0]== NetworkMessages::GAME_OVER)
            {
                //SHOW MESSAGE WITH THE TIME ELAPSED HITS NUMBER FIRE SHOT AND TIME ELAPSED
            }

        }
        std::this_thread::sleep_for (std::chrono::seconds(1));
        //std::this_thread:: (std::chrono::seconds(0.5f));
    }
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
    m_zAxis = m_step;
    //m_front = m_front + step;
    //m_back = m_back - step;
    //m_front = std::clamp(m_front,0.0f,100.0f);
    //m_back = std::clamp(m_back,0.0f,100.0f);
    //m_zAxis = std::clamp(m_zAxis,-3.0f,3.0f);
    m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(m_zAxis) +  ";0.0");
}

void AresGameInputFrame::OnBitmapButton5Click(wxCommandEvent& event)
{
    m_zAxis = -m_step ;
    //m_zAxis = std::clamp(m_zAxis,-3.0f,3.0f);
    //m_front = m_front - step;
    //m_back = m_back + step;
    //m_front = std::clamp(m_front,0.0f,100.0f);
    //m_back = std::clamp(m_back,0.0f,100.0f);
    //m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(m_front) + ";" + to_str(m_back) + ";" + to_str(m_left) + ";" + to_str(m_right));
    m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(m_zAxis) +  ";0.0");
}

void AresGameInputFrame::OnBitmapButton4Click(wxCommandEvent& event)
{
    m_xAxis = -m_step;
    //m_xAxis = std::clamp(m_xAxis,-3.0f,3.0f);
    //m_left = m_left + step;
    //m_right = m_right - step;
    //m_left = std::clamp(m_left,0.0f,100.0f);
    //m_right = std::clamp(m_right,0.0f,100.0f);
    //m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(m_front) + ";" + to_str(m_back) + ";" + to_str(m_left) + ";" + to_str(m_right));
    m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";0.0;" + to_str(m_xAxis));
}

void AresGameInputFrame::OnBitmapButton3Click(wxCommandEvent& event)
{
    m_xAxis = m_step;
    //m_xAxis = std::clamp(m_xAxis,-3.0f,3.0f);
    //m_left = m_left - step;
    //m_right = m_right + step;
    //m_left = std::clamp(m_left,0.0f,100.0f);
    //m_right = std::clamp(m_right,0.0f,100.0f);
    //m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER + ";" + to_str(m_front) + ";" + to_str(m_back) + ";" + to_str(m_left) + ";" + to_str(m_right));
    m_obj->SendMessage(NetworkMessages::MOVEMENT_PLAYER +  ";0.0;"  + to_str(m_xAxis));
}

void AresGameInputFrame::OnSlider1CmdScroll(wxScrollEvent& event)
{
    int pos = event.GetPosition();
    m_obj->SendMessage(NetworkMessages::WEAPON_ELEVATION + ";" + to_str(pos));
}

void AresGameInputFrame::OnSlider2CmdScroll(wxScrollEvent& event)
{
    int pos = event.GetPosition();
    m_obj->SendMessage(NetworkMessages::WEAPON_ROTATION + ";" + to_str(pos));
}

void AresGameInputFrame::OnBitmapButton6Click(wxCommandEvent& event)
{
    m_obj->SendMessage(NetworkMessages::FIRE_WEAPON);
}

void AresGameInputFrame::OnButton1Click(wxCommandEvent& event)
{
    m_obj->SendMessage(NetworkMessages::START_DEMO);
}
