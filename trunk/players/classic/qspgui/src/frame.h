// Copyright (C) 2005-2010 Valeriy Argunov (nporep AT mail DOT ru)
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

#ifndef MAIN_H
	#define MAIN_H

	#include <wx/wx.h>
	#include <wx/fileconf.h>
	#include <wx/cmdline.h>
	#include <wx/fontenum.h>
	#include <wx/fontdlg.h>
	#include <wx/colordlg.h>
	#include <wx/aboutdlg.h>
	#include <wx/aui/aui.h>
	#include "qsp.h"
	#include "transhelper.h"
	#include "inputbox.h"
	#include "textbox.h"
	#include "listbox.h"
	#include "imgcanvas.h"
	#include "initevent.h"

	#include "icons/logo.xpm"
	#include "icons/logo_big.xpm"
	#include "icons/open.xpm"
	#include "icons/new.xpm"
	#include "icons/exit.xpm"
	#include "icons/statusopen.xpm"
	#include "icons/statussave.xpm"
	#include "icons/windowmode.xpm"
	#include "icons/about.xpm"

	#define QSP_LOGO _("Quest Soft Player 5")
	#define QSP_APPNAME wxT("qspgui")
	#define QSP_CONFIG wxT("qspgui.cfg")
	#define QSP_SOUNDPLUGINS wxT("sound")
	#define QSP_MIDIDLS wxT("sound/midi.dls")

	enum
	{
		ID_BEGOFDYNMENU = 1,
		ID_ENDOFDYNMENU = 150,
		ID_OPENGAME,
		ID_NEWGAME,
		ID_OPENGAMESTAT,
		ID_SAVEGAMESTAT,
		ID_QUICKSAVE,
		ID_VOLUME,
		ID_VOLUME0,
		ID_VOLUME20,
		ID_VOLUME40,
		ID_VOLUME60,
		ID_VOLUME80,
		ID_VOLUME100,
		ID_FONT,
		ID_SELECTFONT,
		ID_USEFONTSIZE,
		ID_COLORS,
		ID_SELECTFONTCOLOR,
		ID_SELECTBACKCOLOR,
		ID_SELECTLINKCOLOR,
		ID_SELECTLANG,
		ID_TOGGLEWINMODE,
		ID_TOGGLEOBJS,
		ID_TOGGLEACTS,
		ID_TOGGLEDESC,
		ID_TOGGLEINPUT,
		ID_TOGGLECAPTIONS,
		ID_TOGGLEHOTKEYS,
		ID_SHOWHIDE,
		ID_MAINDESC,
		ID_VARSDESC,
		ID_OBJECTS,
		ID_ACTIONS,
		ID_VIEWPIC,
		ID_INPUT,
		ID_TIMER,

		ID_DUMMY
	};

	class QSPFrame : public wxFrame
	{
		DECLARE_CLASS(QSPFrame)
		DECLARE_EVENT_TABLE()
	public:
		// C-tors / D-tor
		QSPFrame(const wxString &configPath, QSPTranslationHelper *transhelper);
		virtual ~QSPFrame();

		// Methods
		void SaveSettings();
		void LoadSettings();
		void EnableControls(bool status, bool isExtended = false);
		void ShowPane(wxWindowID id, bool isShow);
		void ApplyParams();
		void DeleteMenu();
		void AddMenuItem(const wxString &name, const wxString &imgPath);
		void ShowMenu();

		// Accessors
		wxTimer *GetTimer() const { return m_timer; }
		QSPTextBox *GetDesc() const { return m_desc; }
		QSPTextBox *GetVars() const { return m_vars; }
		QSPInputBox *GetInput() const { return m_input; }
		QSPListBox *GetActions() const { return m_actions; }
		QSPListBox *GetObjects() const { return m_objects; }
		QSPImgCanvas *GetImgView() const { return m_imgView; }
		wxMenu *GetGameMenu() const { return m_gameMenu; }
		bool GetIsShowHotkeys() const { return m_isShowHotkeys; }
		bool GetIsQuit() const { return m_isQuit; }
	protected:
		// Internal methods
		void ShowError();
		void UpdateTitle();
		void ReCreateGUI();
		void RefreshUI();
		void ApplyFont(const wxFont& font);
		bool ApplyFontSize(int size);
		bool ApplyFontName(const wxString& name);
		bool ApplyFontColor(const wxColour& color);
		bool ApplyBackColor(const wxColour& color);
		bool ApplyLinkColor(const wxColour& color);
		void CallPaneFunc(wxWindowID id, QSP_BOOL isShow) const;
		void TogglePane(wxWindowID id);
		void SetOverallVolume(int percents);
		void OpenGameFile(const wxString& path);

		// Events
		void OnInit(wxInitEvent& event);
		void OnClose(wxCloseEvent& event);
		void OnIdle(wxIdleEvent& event);
		void OnTimer(wxTimerEvent& event);
		void OnMenu(wxCommandEvent& event);
		void OnQuit(wxCommandEvent& event);
		void OnOpenGame(wxCommandEvent& event);
		void OnNewGame(wxCommandEvent& event);
		void OnOpenGameStat(wxCommandEvent& event);
		void OnSaveGameStat(wxCommandEvent& event);
		void OnQuickSave(wxCommandEvent& event);
		void OnSelectFont(wxCommandEvent& event);
		void OnUseFontSize(wxCommandEvent& event);
		void OnSelectFontColor(wxCommandEvent& event);
		void OnSelectBackColor(wxCommandEvent& event);
		void OnSelectLinkColor(wxCommandEvent& event);
		void OnSelectLang(wxCommandEvent& event);
		void OnToggleWinMode(wxCommandEvent& event);
		void OnToggleObjs(wxCommandEvent& event);
		void OnToggleActs(wxCommandEvent& event);
		void OnToggleDesc(wxCommandEvent& event);
		void OnToggleInput(wxCommandEvent& event);
		void OnToggleCaptions(wxCommandEvent& event);
		void OnToggleHotkeys(wxCommandEvent& event);
		void OnVolume(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		void OnLinkClicked(wxHtmlLinkEvent& event);
		void OnObjectChange(wxCommandEvent& event);
		void OnActionChange(wxCommandEvent& event);
		void OnActionDblClick(wxCommandEvent& event);
		void OnInputTextChange(wxCommandEvent& event);
		void OnInputTextEnter(wxCommandEvent& event);
		void OnKey(wxKeyEvent& event);
		void OnWheel(wxMouseEvent& event);
		void OnPaneClose(wxAuiManagerEvent& event);
		void OnDropFiles(wxDropFilesEvent& event);

		// Fields
		bool m_isGameOpened;
		wxString m_savedGamePath;
		wxString m_configPath;
		wxString m_configDefPath;
		QSPTranslationHelper *m_transhelper;
		wxTimer *m_timer;
		QSPTextBox *m_desc;
		QSPTextBox *m_vars;
		QSPInputBox *m_input;
		QSPListBox *m_objects;
		QSPListBox *m_actions;
		QSPImgCanvas *m_imgView;
		wxMenu *m_gameMenu;
		int m_menuItemId;
		wxMenu *m_menu;
		wxMenu *m_fileMenu;
		wxMenu *m_settingsMenu;
		wxAuiManager *m_manager;
		wxColour m_backColor;
		wxColour m_linkColor;
		wxColour m_fontColor;
		int m_fontSize;
		wxString m_fontName;
		bool m_isUseFontSize;
		bool m_isProcessEvents;
		bool m_isQuit;
		bool m_isShowHotkeys;
		int m_volume;
	};

#endif
