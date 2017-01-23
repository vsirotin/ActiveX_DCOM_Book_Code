// TaskStart.h : main header file for the TASKSTART application
//

#if !defined(AFX_TASKSTART_H__4483FC26_911B_11D1_AD23_444553540000__INCLUDED_)
#define AFX_TASKSTART_H__4483FC26_911B_11D1_AD23_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTaskStartApp:
// See TaskStart.cpp for the implementation of this class
//

class CTaskStartApp : public CWinApp
{
public:
	CTaskStartApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskStartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTaskStartApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKSTART_H__4483FC26_911B_11D1_AD23_444553540000__INCLUDED_)
