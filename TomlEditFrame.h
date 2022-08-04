#pragma once

#include "gui.h"
#include <toml.hpp>

using TomlObj = toml::basic_value<toml::preserve_comments, std::unordered_map, std::vector>;

class TomlEditFrame : public MainFrame {
public:
	TomlEditFrame();

	void showError(const wxString& msg);
	void showInfo(const wxString& msg);
	void openAndParse(const wxString& path);
	void refresh();
	wxPGProperty* makeValue(const wxString& name, TomlObj& obj, bool insertDirect = false);

	// MainFrame interface
protected:
	void onFileOpen(wxCommandEvent& event) override;

	TomlObj m_toml;
};
