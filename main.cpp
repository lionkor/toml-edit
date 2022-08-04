#include <wx/wxprec.h>

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "TomlEditFrame.h"

class TomlEditApp : public wxApp
{
public:
	virtual bool OnInit() {
		auto *frame = new TomlEditFrame();
		frame->Show(true);
		return true;
	}
};

wxIMPLEMENT_APP(TomlEditApp);
