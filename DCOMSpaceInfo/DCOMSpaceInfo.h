// DCOMSpaceInfo.h : main header file for the DCOMSPACEINFO application
//

#if !defined(AFX_DCOMSPACEINFO_H__EEB67428_087B_11D2_B890_808E7145DC12__INCLUDED_)
#define AFX_DCOMSPACEINFO_H__EEB67428_087B_11D2_B890_808E7145DC12__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoApp:
// See DCOMSpaceInfo.cpp for the implementation of this class
//

class CDCOMSpaceInfoApp : public CWinApp
{
public:
	CDCOMSpaceInfoApp();

//== Atributes
	UINT m_uSvrCount;
	UINT m_uClientCount;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCOMSpaceInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CDCOMSpaceInfoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CDCOMSpaceInfoApp theApp;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCOMSPACEINFO_H__EEB67428_087B_11D2_B890_808E7145DC12__INCLUDED_)
