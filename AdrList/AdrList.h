// AdrList.h : main header file for the ADRLIST application
//

#if !defined(AFX_ADRLIST_H__2D81BA48_C815_11D1_B890_EF240A666978__INCLUDED_)
#define AFX_ADRLIST_H__2D81BA48_C815_11D1_B890_EF240A666978__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdrListApp:
// See AdrList.cpp for the implementation of this class
//

class CAdrListApp : public CWinApp
{
public:
	CAdrListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CAdrListApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLIST_H__2D81BA48_C815_11D1_B890_EF240A666978__INCLUDED_)
