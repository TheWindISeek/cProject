/***************************************************************
 * Name:      wxHelloApp.cpp
 * Purpose:   Code for Application Class
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxHelloApp.h"

//(*AppHeaders
#include "wxHelloMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxHelloApp);

bool wxHelloApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxHelloFrame* Frame = new wxHelloFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
