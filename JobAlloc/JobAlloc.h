// JobAlloc.h : main header file for the JOBALLOC application
//

#if !defined(AFX_JOBALLOC_H__43E33187_92FD_11D1_A249_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOC_H__43E33187_92FD_11D1_A249_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJobAllocApp:
// See JobAlloc.cpp for the implementation of this class
//

class CJobAllocApp : public CWinApp
{
public:
	CString m_strName;
	CJobAllocApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJobAllocApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


extern CJobAllocApp theApp;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOC_H__43E33187_92FD_11D1_A249_00A0C941DD59__INCLUDED_)
