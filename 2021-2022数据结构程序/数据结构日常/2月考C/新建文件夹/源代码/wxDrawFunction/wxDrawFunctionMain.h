/***************************************************************
 * Name:      wxDrawFunctionMain.h
 * Purpose:   Defines Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#ifndef WXDRAWFUNCTIONMAIN_H
#define WXDRAWFUNCTIONMAIN_H

//(*Headers(wxDrawFunctionFrame)
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/toolbar.h>
//*)

class wxDrawFunctionFrame: public wxFrame
{
    public:

        wxDrawFunctionFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxDrawFunctionFrame();

    private:

        //(*Handlers(wxDrawFunctionFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnToolBarDrawLineClicked(wxCommandEvent& event);
        void OnToolBarDrawLinesClicked(wxCommandEvent& event);
        void OnToolBarSplineClicked(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxDrawFunctionFrame)
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        static const long ID_TOOLBARDRAWLINE;
        static const long ID_TOOLBARDRAWLINE2;
        static const long ID_TOOLBARSPLINE;
        static const long ID_TOOLBAR1;
        //*)

        //(*Declarations(wxDrawFunctionFrame)
        wxStatusBar* StatusBar1;
        wxToolBar* ToolBar1;
        wxToolBarToolBase* ToolBarItem1;
        wxToolBarToolBase* ToolBarItem2;
        wxToolBarToolBase* ToolBarItem3;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXDRAWFUNCTIONMAIN_H
