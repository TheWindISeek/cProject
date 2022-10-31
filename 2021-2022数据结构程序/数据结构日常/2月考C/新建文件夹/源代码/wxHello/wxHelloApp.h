/***************************************************************
 * Name:      wxHelloApp.h
 * Purpose:   Defines Application Class
 * Author:    fontain (fontain@163.com)
 * Created:   2019-11-14
 * Copyright: fontain ()
 * License:
 **************************************************************/

#ifndef WXHELLOAPP_H
#define WXHELLOAPP_H

#include <wx/app.h>

class wxHelloApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // WXHELLOAPP_H
