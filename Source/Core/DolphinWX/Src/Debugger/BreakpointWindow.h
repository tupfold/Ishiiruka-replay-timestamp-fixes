// Copyright (C) 2003 Dolphin Project.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, version 2.0.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License 2.0 for more details.

// A copy of the GPL 2.0 should have been included with the program.
// If not, see http://www.gnu.org/licenses/

// Official SVN repository and contact information can be found at
// http://code.google.com/p/dolphin-emu/

#ifndef __BREAKPOINTWINDOW_h__
#define __BREAKPOINTWINDOW_h__

class CBreakPointView;
class CBreakPointBar;
class CCodeWindow;
class wxListEvent;
class IniFile;

class CBreakPointWindow
	: public wxPanel
{
public:

	CBreakPointWindow(CCodeWindow* _pCodeWindow,
		wxWindow* parent,
		wxWindowID id = wxID_ANY,
		const wxString& title = _("Breakpoints"),
		const wxPoint& pos = wxDefaultPosition,
		const wxSize& size = wxDefaultSize,
		long style = wxTAB_TRAVERSAL | wxBORDER_NONE);

	void NotifyUpdate();

	void OnDelete();
	void OnClear();
	void OnAddBreakPoint();
	void OnAddMemoryCheck();
	void SaveAll();
	void LoadAll();

private:
	DECLARE_EVENT_TABLE();

	enum
	{
		ID_TOOLBAR = 501,
		ID_BPS = 1002,
	};

	CBreakPointBar* m_BreakPointBar;
	CBreakPointView* m_BreakPointListView;
	CCodeWindow* m_pCodeWindow;

	void OnClose(wxCloseEvent& event);
	void OnSelectToolbar(wxListEvent& event);
	void OnSelectBP(wxListEvent& event);
	void OnRightClick(wxListEvent& event);
	void CreateGUIControls();
};

#endif