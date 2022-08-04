#include "TomlEditFrame.h"

#include <wx/filedlg.h>
#include <wx/msgdlg.h>
#include <wx/propgrid/propgrid.h>

TomlEditFrame::TomlEditFrame()
	: MainFrame(nullptr) { }

void TomlEditFrame::showError(const wxString& msg) {
	std::cerr << "Error: " << msg << std::endl;
	wxMessageDialog diag(this, msg, _("An error occurred"));
	diag.ShowModal();
}

void TomlEditFrame::showInfo(const wxString& msg) {
	std::cerr << "Info: " << msg << std::endl;
	wxMessageDialog diag(this, msg, _("Info"));
	diag.ShowModal();
}

void TomlEditFrame::openAndParse(const wxString& path) {
	try {
		m_toml = toml::parse(path.c_str().AsChar());
		refresh();
	} catch (const std::exception& e) {
		showError(wxString(_("Error opening or parsing file: ")) + e.what());
	}
}

void TomlEditFrame::refresh() {
	m_propertyGrid->Clear();
	//m_propertyGrid->SetColumnCount(2);
	makeValue("root", m_toml, true);
}

wxPGProperty* TomlEditFrame::makeValue(const wxString& name, TomlObj& obj, bool insertDirect) {
	wxPGProperty* prop = nullptr;
	switch (obj.type()) {
	case toml::value_t::empty:
		break;
	case toml::value_t::boolean:
		prop = new wxBoolProperty(name, name, obj.as_boolean());
		break;
	case toml::value_t::integer:
		prop = new wxIntProperty(name, name, obj.as_integer());
		break;
	case toml::value_t::floating:
		prop = new wxFloatProperty(name, name, obj.as_floating());
		break;
	case toml::value_t::string:
		prop = new wxStringProperty(name, name, obj.as_string().str.c_str());
		break;
	case toml::value_t::offset_datetime:
		prop = new wxDateProperty(name, name, wxDateTime(obj.as_offset_datetime()));
		break;
	case toml::value_t::local_datetime:
		prop = new wxDateProperty(name, name, wxDateTime(obj.as_local_datetime()));
		break;
	case toml::value_t::local_date:
		prop = new wxDateProperty(name, name, wxDateTime(obj.as_local_date()));
		break;
	case toml::value_t::local_time: {
		auto t = obj.as_local_time();
		prop = new wxDateProperty(name, name, wxDateTime(t.hour, t.minute, t.second, t.millisecond));
		break;
	}
	case toml::value_t::array:
		break;
	case toml::value_t::table:
		prop = new wxStringProperty(name, name);
		prop->SetFlagRecursively(wxPG_PROP_READONLY, true);
		for (auto& [k, v] : obj.as_table()) {
			auto value = makeValue(k.c_str(), v);
			if (value) {
				if (!insertDirect) {
					prop->AppendChild(value);
				} else {
					m_propertyGrid->Append(value);
				}
			}
		}
		break;
	}
	if (prop) {
		prop->SetClientData(&obj);
	}
	return prop;
}

void TomlEditFrame::onFileOpen(wxCommandEvent&) {
	wxFileDialog diag(this, _("Open TOML file"), wxEmptyString, wxEmptyString, "*.toml", wxFD_OPEN);
	auto res = diag.ShowModal();
	if (res != wxID_CANCEL) {
		openAndParse(diag.GetPath());
	}
}
