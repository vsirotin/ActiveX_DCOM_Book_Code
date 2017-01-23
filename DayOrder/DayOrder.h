// DayOrder.h : main header file for the DAYORDER application
//

#if !defined(AFX_DAYORDER_H__9A13BCE5_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
#define AFX_DAYORDER_H__9A13BCE5_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDayOrderApp:
// See DayOrder.cpp for the implementation of this class
//

class CDayOrderApp : public CWinApp
{
public:
	CDayOrderApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDayOrderApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDayOrderApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAYORDER_H__9A13BCE5_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
