/***************************************************************
 * Name:      wxBrushPenMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#include "wxBrushPenMain.h"
#include <wx/msgdlg.h>
#include <wx/wx.h>
#include <time.h>
//(*InternalHeaders(wxBrushPenFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
    short_f, long_f
};

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

//(*IdInit(wxBrushPenFrame)
const long wxBrushPenFrame::ID_BUTTON1 = wxNewId();
const long wxBrushPenFrame::ID_BUTTON2 = wxNewId();
const long wxBrushPenFrame::ID_BUTTON3 = wxNewId();
const long wxBrushPenFrame::ID_BUTTON4 = wxNewId();
const long wxBrushPenFrame::ID_BUTTON5 = wxNewId();
const long wxBrushPenFrame::ID_BUTTON6 = wxNewId();
const long wxBrushPenFrame::ID_PANEL1 = wxNewId();
const long wxBrushPenFrame::ID_PANEL2 = wxNewId();
const long wxBrushPenFrame::idMenuQuit = wxNewId();
const long wxBrushPenFrame::idMenuAbout = wxNewId();
const long wxBrushPenFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(wxBrushPenFrame,wxFrame)
    //(*EventTable(wxBrushPenFrame)
    //*)
END_EVENT_TABLE()

wxBrushPenFrame::wxBrushPenFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(wxBrushPenFrame)
    wxBoxSizer* BoxSizer1;
    wxBoxSizer* BoxSizer2;
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("»­±Ê»­Ë¢ÊµÑé"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(685,450));
    Move(wxPoint(-1,-1));
    BoxSizer1 = new wxBoxSizer(wxVERTICAL);
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    BoxSizer2 = new wxBoxSizer(wxHORIZONTAL);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Ëæ»ú±³¾°ÇåÆÁ"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON1"));
    BoxSizer2->Add(Button1, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("±ÊË¢Ìî³äÑÝÊ¾"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON2"));
    BoxSizer2->Add(Button2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button3 = new wxButton(Panel1, ID_BUTTON3, _("Ëæ»úÏß¿íÍ¼Ïñ»­±ÊÉèÖÃÑÝÊ¾"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON3"));
    BoxSizer2->Add(Button3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button4 = new wxButton(Panel1, ID_BUTTON4, _("Ëæ»úÏß¿íÏßÉ«ÑÝÊ¾"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON4"));
    BoxSizer2->Add(Button4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button5 = new wxButton(Panel1, ID_BUTTON5, _("ÏßÐÍÑÝÊ¾"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON5"));
    BoxSizer2->Add(Button5, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Button6 = new wxButton(Panel1, ID_BUTTON6, _("Í¼Ïñ»æÖÆ"), wxDefaultPosition, wxDefaultSize, 0, wxDefaultValidator, _T("ID_BUTTON6"));
    BoxSizer2->Add(Button6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5);
    Panel1->SetSizer(BoxSizer2);
    BoxSizer2->Fit(Panel1);
    BoxSizer2->SetSizeHints(Panel1);
    BoxSizer1->Add(Panel1, 0, wxALL|wxEXPAND, 5);
    Panel2 = new wxPanel(this, ID_PANEL2, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL, _T("ID_PANEL2"));
    BoxSizer1->Add(Panel2, 1, wxALL|wxEXPAND, 5);
    SetSizer(BoxSizer1);
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
    SetSizer(BoxSizer1);
    Layout();

    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton2Click);
    Connect(ID_BUTTON3,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton3Click);
    Connect(ID_BUTTON4,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton4Click);
    Connect(ID_BUTTON5,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton5Click);
    Connect(ID_BUTTON6,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&wxBrushPenFrame::OnButton6Click);
    Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxBrushPenFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&wxBrushPenFrame::OnAbout);
    //*)
}

wxBrushPenFrame::~wxBrushPenFrame()
{
    //(*Destroy(wxBrushPenFrame)
    //*)
}

void wxBrushPenFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void wxBrushPenFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}

void wxBrushPenFrame::OnButton1Click(wxCommandEvent& event)
{
    srand(time(0));
    wxClientDC dc(Panel2);
    wxColour c(rand()%255,rand()%255,rand()%255,rand()%255);
    wxBrush br(c);
    dc.SetBackground(br);
    dc.Clear();
    //dc.SetBrush(br);
    //dc.DrawRectangle(100,100,300,300);
}

void wxBrushPenFrame::OnButton2Click(wxCommandEvent& event)
{
    wxBrushStyle s[]= {wxBRUSHSTYLE_SOLID,
                       wxBRUSHSTYLE_TRANSPARENT,
                       wxBRUSHSTYLE_BDIAGONAL_HATCH,
                       wxBRUSHSTYLE_CROSSDIAG_HATCH,
                       wxBRUSHSTYLE_FDIAGONAL_HATCH,
                       wxBRUSHSTYLE_CROSS_HATCH,
                       wxBRUSHSTYLE_HORIZONTAL_HATCH,
                       wxBRUSHSTYLE_VERTICAL_HATCH,
                       wxBRUSHSTYLE_FIRST_HATCH,
                       wxBRUSHSTYLE_LAST_HATCH,
                       wxBRUSHSTYLE_STIPPLE,
                       wxBRUSHSTYLE_STIPPLE_MASK_OPAQUE
                      };
    wxBitmap bm_mono(_("b.bmp"),wxBITMAP_TYPE_BMP);
    wxMask mask(bm_mono,*wxBLACK);
    bm_mono.SetMask(&mask);
    wxBrush br(*wxBLACK);
    br.SetStipple(bm_mono);
    wxClientDC dc(Panel2);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    for(int j=0; j<3; j++)
    {
        for(int i=0; i<4; i++)
        {
            br.SetStyle(s[j*4+i]);
            dc.SetBrush(br);
            dc.DrawRectangle(10+220*i,10+220*j,200,200);
        }
    }
}

void wxBrushPenFrame::OnButton3Click(wxCommandEvent& event)
{
    wxBitmap bm_mono(_("b.bmp"),wxBITMAP_TYPE_BMP);
    wxMask mask(bm_mono,*wxBLACK);
    bm_mono.SetMask(&mask);
    wxBrush br(*wxBLACK);
    br.SetStipple(bm_mono);
    wxClientDC dc(Panel2);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    srand(time(0));
    wxPen pen(bm_mono,rand()%30);
    int w,h;
    Panel2->GetSize(&w,&h);
    int x=rand()%w;
    int y=rand()%h;
    for(int i=0; i<30; i++)
    {
        int x1=rand()%w;
        int y1=rand()%h;
        dc.SetPen(pen);
        dc.DrawLine(x,y,x1,y1);
        x=x1;
        y=y1;
    }

}

void wxBrushPenFrame::OnButton4Click(wxCommandEvent& event)
{
    wxClientDC dc(Panel2);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    srand(time(0));
    wxColor c(rand()%255,rand()%255,rand()%255,rand()%255);
    wxPen pen(c,rand()%30,wxPENSTYLE_SOLID);
    int w,h;
    Panel2->GetSize(&w,&h);
    int x=rand()%w;
    int y=rand()%h;
    for(int i=0; i<30; i++)
    {
        int x1=rand()%w;
        int y1=rand()%h;
        dc.SetPen(pen);
        dc.DrawLine(x,y,x1,y1);
        x=x1;
        y=y1;
    }
}

void wxBrushPenFrame::OnButton5Click(wxCommandEvent& event)
{
    wxPenStyle styles[]= {wxPENSTYLE_SOLID,
                          wxPENSTYLE_DOT,
                          wxPENSTYLE_LONG_DASH,
                          wxPENSTYLE_SHORT_DASH,
                          wxPENSTYLE_DOT_DASH,
                          wxPENSTYLE_USER_DASH,
                          wxPENSTYLE_TRANSPARENT,
                          wxPENSTYLE_BDIAGONAL_HATCH,
                          wxPENSTYLE_CROSSDIAG_HATCH,
                          wxPENSTYLE_FDIAGONAL_HATCH,
                          wxPENSTYLE_CROSS_HATCH,
                          wxPENSTYLE_HORIZONTAL_HATCH,
                          wxPENSTYLE_VERTICAL_HATCH,
                          wxPENSTYLE_FIRST_HATCH,
                          wxPENSTYLE_LAST_HATCH
                         };
    wxClientDC dc(Panel2);
    dc.SetBackground(*wxWHITE_BRUSH);
    dc.Clear();
    wxPen pen=*wxBLUE;
    pen.SetWidth(15);
    for(int y=0;y<15;y++){
        pen.SetStyle(styles[y]);
        dc.SetPen(pen);
        dc.DrawLine(100,30+y*40,800,30+y*40);
    }
}

void wxBrushPenFrame::OnButton6Click(wxCommandEvent& event)
{
    wxClientDC dc(Panel2);
    wxBitmap bm(_("c.png"),wxBITMAP_TYPE_PNG);
    int w,h;
    Panel2->GetSize(&w,&h);
    wxImage image=bm.ConvertToImage().Scale(w,h);
    wxBitmap bm2(image);
    dc.DrawBitmap(bm2,0,0);
}
