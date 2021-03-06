/*
 * This file is part of the Code::Blocks IDE and licensed under the GNU General Public License, version 3
 * http://www.gnu.org/licenses/gpl-3.0.html
 */

#ifndef PROJECTOPTIONSMANIPULATORDLG_H
#define PROJECTOPTIONSMANIPULATORDLG_H

//(*Headers(ProjectOptionsManipulatorDlg)
#include <wx/dialog.h>
class wxTextCtrl;
class wxStaticBoxSizer;
class wxChoice;
class wxFlexGridSizer;
class wxStdDialogButtonSizer;
class wxBoxSizer;
class wxStaticText;
class wxRadioBox;
class wxCheckBox;
//*)

class ProjectOptionsManipulatorDlg: public wxDialog
{
	public:
	  enum EProjectScanOption   { eSearch, eSearchNot, eRemove,
	                              eAdd,    eReplace,   eFiles };
	  enum EProjectSearchOption { eEquals, eContains };
	  enum EProjectOption       { eReplacePattern,
	                              eCompiler,      eLinker,      eResCompiler,
	                              eCompilerPaths, eLinkerPaths, eResCompPaths,
	                              eLinkerLibs,    eCustomVars };
	  enum EProjectLevelOption  { eProject, eTarget };

		ProjectOptionsManipulatorDlg(wxWindow* parent,wxWindowID id=wxID_ANY);
		virtual ~ProjectOptionsManipulatorDlg();

    bool                 GetScanForWorkspace();
    bool                 GetScanForProject();
    size_t               GetProjectIdx();
    EProjectScanOption   GetScanOption();
    EProjectSearchOption GetSearchOption();
    wxString             GetSearchFor();
    wxString             GetReplaceWith();
    wxString             GetCustomVarValue();
    bool                 GetOptionActive(EProjectOption opt);
    bool                 GetOptionActive(EProjectLevelOption opt);

		//(*Declarations(ProjectOptionsManipulatorDlg)
		wxTextCtrl* m_TxtCustomVar;
		wxCheckBox* m_ChkOptionsLinkerPath;
		wxChoice* m_ChoScan;
		wxTextCtrl* m_TxtOptionSearch;
		wxCheckBox* m_ChkOptionsResCompiler;
		wxCheckBox* m_ChkOptionReplacePattern;
		wxCheckBox* m_ChkOptionsResCompPath;
		wxChoice* m_ChoScanProjects;
		wxCheckBox* m_ChkOptionsCompilerPath;
		wxCheckBox* m_ChkOptionsLinker;
		wxTextCtrl* m_TxtOptionReplace;
		wxRadioBox* m_RboSearch;
		wxChoice* m_ChoOptionsLevel;
		wxCheckBox* m_ChkOptionsCompiler;
		wxCheckBox* m_ChkOptionsLinkerLibs;
		wxRadioBox* m_RboOperation;
		wxCheckBox* m_ChkOptionsCustomVar;
		//*)

	protected:

		//(*Identifiers(ProjectOptionsManipulatorDlg)
		static const long ID_CHO_SCAN;
		static const long ID_CHO_SCAN_PROJECTS;
		static const long ID_RBO_OPERATION;
		static const long ID_CHO_OPTIONS_LEVEL;
		static const long ID_TXT_OPTIONS;
		static const long TD_TXT_OPTION_REPLACE;
		static const long ID_CHK_OPTION_REPLACE_PATTERN;
		static const long ID_RBO_SEARCH;
		static const long ID_CHK_OPTIONS_COMPILER;
		static const long ID_CHK_OPTIONS_LINKER;
		static const long ID_CHK_OPTIONS_RES_COMPILER;
		static const long ID_CHK_OPTIONS_COMPILER_PATH;
		static const long ID_CHK_OPTIONS_LINKER_PATH;
		static const long ID_CHK_OPTIONS_RES_COMP_PATH;
		static const long ID_CHK_OPTIONS_LINKER_LIBS;
		static const long ID_CHK_OPTIONS_CUSTOM_VAR;
		static const long ID_TXT_CUSTOM_VAR;
		//*)

	private:

		//(*Handlers(ProjectOptionsManipulatorDlg)
		void OnScanSelect(wxCommandEvent& event);
		void OnOperationSelect(wxCommandEvent& event);
		//*)

		void OnOk(wxCommandEvent& event);

		DECLARE_EVENT_TABLE()
};

#endif
