/***************************************************************
 * Name:      wxHelloMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxHelloMain.h"
#include <wx/msgdlg.h>

//(*InternalHeaders(wxHelloFrame)
#include <wx/intl.h>
#include <wx/string.h>
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

//(*IdInit(wxHelloFrame)
const long wxHelloFrame::ID_BUTTON1 = wxNewId();
const long wxHelloFrame::ID_BUTTON2 = wxNewId();
const long wxHelloFrame::ID_STATICTEXT1 = wxNewId();
const long wxHelloFrame::idMenuQuit = wxNewId();
const long wxHelloFrame::idMenuAbout = wxNewId();
const long wxHelloFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxHelloFrame,wxFrame)
    //(*EventTable(wxHelloFrame)
    //*)
END_EVENT_TABLE()

wxHelloFrame::wxHelloFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxHelloFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("HelloWorld"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(400,300));
    Button1 = new wxButton(this, ID_BUTTON1, _("SayHello"), wxPoint(120,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(this, ID_BUTTON2, _("Quit"), wxPoint(224,208), wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("Label"), wxPoint(40,72), wxSize(352,14), 0, _T("ID_STATICTEXT1"));
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

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHelloFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxHelloFrame::OnButton2Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHelloFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxHelloFrame::OnAbout);
    //*)
}

wxHelloFrame::~wxHelloFrame()
{
    //(*Destroy(wxHelloFrame)
    //*)
}

void wxHelloFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxHelloFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxHelloFrame::OnButton1Click(wxCommandEvent& event)
{
    if(StaticText1->GetLabel().Contains(wxT("world")))
        StaticText1->SetLabel(StaticText1->GetLabel() + wxT(" again"));
    else
        StaticText1->SetLabel(wxT("Hello world"));
}

void wxHelloFrame::OnButton2Click(wxCommandEvent& event)
{
    Close(TRUE);
}
