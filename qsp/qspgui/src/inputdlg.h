// Copyright (C) 2005-2009 Valeriy Argunov (nporep AT mail DOT ru)
/*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#ifndef INPUTDLG_H
	#define INPUTDLG_H

	#include <wx/wx.h>
	#include <wx/statline.h>
	#include <wx/valgen.h>
	#include "textbox.h"

	enum
	{
		ID_INPUT_DESC
	};

	class QSPInputDlg : public wxDialog
	{
		DECLARE_CLASS(QSPInputDlg)
		DECLARE_EVENT_TABLE()
	public:
		// C-tors / D-tor
		QSPInputDlg(wxWindow* parent,
					wxWindowID id,
					const wxColour& backColor,
					const wxColour& fontColor,
					const wxFont& font,
					const wxString& caption,
					const wxString& text,
					bool isHtml,
					const wxString& gamePath);

		// Accessors
		wxString GetText() const { return m_text; }
	protected:
		// Events
		void OnLinkClicked(wxHtmlLinkEvent& event);

		// Fields
		QSPTextBox *m_desc;
		wxString m_text;
	};

#endif
