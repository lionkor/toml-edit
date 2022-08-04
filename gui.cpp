///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "gui.h"

///////////////////////////////////////////////////////////////////////////

MainFrame::MainFrame( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 200,100 ), wxDefaultSize );

	m_menubar1 = new wxMenuBar( 0 );
	m_menuFile = new wxMenu();
	wxMenuItem* m_menuFileOpen;
	m_menuFileOpen = new wxMenuItem( m_menuFile, wxID_ANY, wxString( _("Open") ) + wxT('\t') + wxT("Ctrl+O"), _("Open a TOML file"), wxITEM_NORMAL );
	m_menuFile->Append( m_menuFileOpen );

	m_menubar1->Append( m_menuFile, _("File") );

	this->SetMenuBar( m_menubar1 );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	m_propertyGrid = new wxPropertyGrid(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxPG_DEFAULT_STYLE);
	bSizer2->Add( m_propertyGrid, 1, wxALL|wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	m_statusBar2 = this->CreateStatusBar( 1, wxSTB_SIZEGRIP, wxID_ANY );

	this->Centre( wxBOTH );

	// Connect Events
	m_menuFile->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( MainFrame::onFileOpen ), this, m_menuFileOpen->GetId());
}

MainFrame::~MainFrame()
{
	// Disconnect Events

}
