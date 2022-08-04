#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "gui.h"

class TomlEditApp : public wxApp
{
public:
	virtual bool OnInit() {
		auto *frame = new MainFrame(nullptr);
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(TomlEditApp);
