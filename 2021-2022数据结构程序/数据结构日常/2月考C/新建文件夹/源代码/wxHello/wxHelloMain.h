/***************************************************************
 * Name:      wxHelloMain.h
 * Purpose:   Defines Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#ifndef WXHELLOMAIN_H
#define WXHELLOMAIN_H

//(*Headers(wxHelloFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/menu.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
//*)

class wxHelloFrame: public wxFrame
{
    public:

        wxHelloFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~wxHelloFrame();

    private:

        //(*Handlers(wxHelloFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        //*)

        //(*Identifiers(wxHelloFrame)
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICTEXT1;
        static const long idMenuQuit;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(wxHelloFrame)
        wxButton* Button1;
        wxButton* Button2;
        wxStaticText* StaticText1;
        wxStatusBar* StatusBar1;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // WXHELLOMAIN_H
