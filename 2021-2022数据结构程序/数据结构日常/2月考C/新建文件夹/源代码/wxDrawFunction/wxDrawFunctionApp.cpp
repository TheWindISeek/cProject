/***************************************************************
 * Name:      wxDrawFunctionApp.cpp
 * Purpose:   Code for Application Class
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxDrawFunctionApp.h"

//(*AppHeaders
#include "wxDrawFunctionMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxDrawFunctionApp);

bool wxDrawFunctionApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxDrawFunctionFrame* Frame = new wxDrawFunctionFrame(0);
    	Frame->Show();
    	Frame->Maximize(true);
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
