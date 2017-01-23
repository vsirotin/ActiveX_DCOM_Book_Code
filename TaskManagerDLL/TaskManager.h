// TaskManager.h : main header file for the TASKMANAGER application
//

#if !defined(AFX_TASKMANAGER_H__401F308C_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGER_H__401F308C_93C7_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerApp:
// See TaskManager.cpp for the implementation of this class
//

class CTaskManagerApp : public CWinApp
{
public:
	CTaskManagerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTaskManagerApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGER_H__401F308C_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
