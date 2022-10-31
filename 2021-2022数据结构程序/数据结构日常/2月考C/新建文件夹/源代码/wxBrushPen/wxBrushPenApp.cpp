/***************************************************************
 * Name:      wxBrushPenApp.cpp
 * Purpose:   Code for Application Class
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxBrushPenApp.h"

//(*AppHeaders
#include "wxBrushPenMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(wxBrushPenApp);

bool wxBrushPenApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	wxBrushPenFrame* Frame = new wxBrushPenFrame(0);
    	Frame->Show();
    	Frame->Maximize(true);
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
