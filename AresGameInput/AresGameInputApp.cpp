/***************************************************************
 * Name:      AresGameInputApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Willian Jefferson (willianjefferson7@gmail.com)
 * Created:   2020-01-29
 * Copyright: Willian Jefferson ()
 * License:
 **************************************************************/

#include "wx_pch.h"
#include "AresGameInputApp.h"

//(*AppHeaders
#include "AresGameInputMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(AresGameInputApp);

bool AresGameInputApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	AresGameInputFrame* Frame = new AresGameInputFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
