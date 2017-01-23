// TaskManagerCOM.h : main header file for the TASKMANAGERCOM application
//

#if !defined(AFX_TASKMANAGERCOM_H__88A3FA09_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGERCOM_H__88A3FA09_A12F_11D1_A259_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMApp:
// See TaskManagerCOM.cpp for the implementation of this class
//

class CTaskManagerCOMApp : public CWinApp
{
public:
	CTaskManagerCOMApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerCOMApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTaskManagerCOMApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGERCOM_H__88A3FA09_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
