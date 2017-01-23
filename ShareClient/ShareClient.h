// ShareClient.h : main header file for the SHARECLIENT application
//

#if !defined(AFX_SHARECLIENT_H__BCE3EBC7_13F3_11D2_B890_C88BEC79707C__INCLUDED_)
#define AFX_SHARECLIENT_H__BCE3EBC7_13F3_11D2_B890_C88BEC79707C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShareClientApp:
// See ShareClient.cpp for the implementation of this class
//

class CShareClientApp : public CWinApp
{
public:
	CShareClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShareClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
extern CShareClientApp theApp;

#include <atlbase.h>
extern CComModule _Module;
#include <atlcom.h>
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARECLIENT_H__BCE3EBC7_13F3_11D2_B890_C88BEC79707C__INCLUDED_)
