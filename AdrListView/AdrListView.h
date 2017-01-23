// AdrListView.h : main header file for the ADRLISTVIEW application
//

#if !defined(AFX_ADRLISTVIEW_H__35A69B67_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
#define AFX_ADRLISTVIEW_H__35A69B67_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewApp:
// See AdrListView.cpp for the implementation of this class
//

class CAdrListViewApp : public CWinApp
{
public:
	CAdrListViewApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListViewApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdrListViewApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLISTVIEW_H__35A69B67_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
