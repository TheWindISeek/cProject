/***************************************************************
 * Name:      wxDrawFunctionMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxDrawFunctionMain.h"
#include <wx/msgdlg.h>
#include "wx/wx.h"
#include "stdlib.h"
#include "time.h"
//(*InternalHeaders(wxDrawFunctionFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/image.h>
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

//(*IdInit(wxDrawFunctionFrame)
const long wxDrawFunctionFrame::idMenuQuit = wxNewId();
const long wxDrawFunctionFrame::idMenuAbout = wxNewId();
const long wxDrawFunctionFrame::ID_STATUSBAR1 = wxNewId();
const long wxDrawFunctionFrame::ID_TOOLBARDRAWLINE = wxNewId();
const long wxDrawFunctionFrame::ID_TOOLBARDRAWLINE2 = wxNewId();
const long wxDrawFunctionFrame::ID_TOOLBARSPLINE = wxNewId();
const long wxDrawFunctionFrame::ID_TOOLBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxDrawFunctionFrame,wxFrame)
    //(*EventTable(wxDrawFunctionFrame)
    //*)
END_EVENT_TABLE()

wxDrawFunctionFrame::wxDrawFunctionFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxDrawFunctionFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, id, _("wxWidgets绘图函数演示程序"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
    SetClientSize(wxSize(616,450));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\d2661a31f9635386d25c4740a09dd17c.png"))));
    	SetIcon(FrameIcon);
    }
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
    ToolBar1 = new wxToolBar(this, ID_TOOLBAR1, wxDefaultPosition, wxDefaultSize, wxTB_HORIZONTAL|wxNO_BORDER, _T("ID_TOOLBAR1"));
    ToolBarItem1 = ToolBar1->AddTool(ID_TOOLBARDRAWLINE, _("画线"), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\01.png"))), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\01.png"))), wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem2 = ToolBar1->AddTool(ID_TOOLBARDRAWLINE2, _("画线2"), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\02.png"))), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\02.png"))), wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBarItem3 = ToolBar1->AddTool(ID_TOOLBARSPLINE, _("样条曲线"), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\03.png"))), wxBitmap(wxImage(_T("C:\\Users\\Administrator\\Desktop\\03.png"))), wxITEM_NORMAL, wxEmptyString, wxEmptyString);
    ToolBar1->Realize();
    SetToolBar(ToolBar1);

    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxDrawFunctionFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxDrawFunctionFrame::OnAbout);
    Connect(ID_TOOLBARDRAWLINE,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&wxDrawFunctionFrame::OnToolBarDrawLineClicked);
    Connect(ID_TOOLBARDRAWLINE2,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&wxDrawFunctionFrame::OnToolBarDrawLinesClicked);
    Connect(ID_TOOLBARSPLINE,wxEVT_COMMAND_TOOL_CLICKED,(wxObjectEventFunction)&wxDrawFunctionFrame::OnToolBarSplineClicked);
    //*)
}

wxDrawFunctionFrame::~wxDrawFunctionFrame()
{
    //(*Destroy(wxDrawFunctionFrame)
    //*)
}

void wxDrawFunctionFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxDrawFunctionFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxDrawFunctionFrame::OnToolBarDrawLineClicked(wxCommandEvent& event)
{
    wxClientDC dc(this);
    int w,h;
    GetSize(&w,&h);
    dc.Clear();
    srand(time(0));
    int x=rand()%w;
    int y=rand()%h;
    for(int i=0;i<30;i++){
        int x1=rand()%w;
        int y1=rand()%h;
        dc.DrawLine(x,y,x1,y1);
        x=x1;y=y1;
    }
}

void wxDrawFunctionFrame::OnToolBarDrawLinesClicked(wxCommandEvent& event)
{
    wxClientDC dc(this);
    wxPoint points[20];
    int w,h;
    GetSize(&w,&h);
    srand(time(0));
    for(int i=0;i<20;i++){
        points[i]=wxPoint(rand()%w,rand()%h);
    }
    dc.Clear();
    dc.DrawLines(20,points);
}

void wxDrawFunctionFrame::OnToolBarSplineClicked(wxCommandEvent& event)
{
    wxClientDC dc(this);
    wxPoint points[20];
    int w,h;
    GetSize(&w,&h);
    srand(time(0));
    for(int i=0;i<20;i++){
        points[i]=wxPoint(rand()%w,rand()%h);
    }
    dc.Clear();
    dc.DrawSpline(20,points);
}
