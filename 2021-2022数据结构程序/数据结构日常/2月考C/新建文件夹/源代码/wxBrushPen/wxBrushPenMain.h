/***************************************************************
 * Name:      wxBrushPenMain.h
 * Purpose:   Defines Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#ifndef WXBRUSHPENMAIN_H
#define WXBRUSHPENMAIN_H

//(*Headers(wxBrushPenFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/sizer.h>
#include <wx/statusbr.h>
//*)

class wxBrushPenFrame: public wxFrame
{
    public:

        wxBrushPenFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxBrushPenFrame();

    private:

        //(*Handlers(wxBrushPenFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton3Click(wxCommandEvent& event);
        void OnButton4Click(wxCommandEvent& event);
        void OnButton5Click(wxCommandEvent& event);
        void OnButton6Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxBrushPenFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_BUTTON3;
        static const long ID_BUTTON4;
        static const long ID_BUTTON5;
        static const long ID_BUTTON6;
        static const long ID_PANEL1;
        static const long ID_PANEL2;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxBrushPenFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxButton* Button3;
        wxButton* Button4;
        wxButton* Button5;
        wxButton* Button6;
        wxPanel* Panel1;
        wxPanel* Panel2;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXBRUSHPENMAIN_H
