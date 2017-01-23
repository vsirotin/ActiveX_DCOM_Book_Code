// AcDoc.h : main header file for the ACDOC application
//

#if !defined(AFX_ACDOC_H__4713B545_062B_11D2_B890_C54647D3D618__INCLUDED_)
#define AFX_ACDOC_H__4713B545_062B_11D2_B890_C54647D3D618__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAcDocApp:
// See AcDoc.cpp for the implementation of this class
//

class CAcDocApp : public CWinApp
{
public:
	CAcDocApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcDocApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	COleTemplateServer m_server;
		// Server object for document creation

	//{{AFX_MSG(CAcDocApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACDOC_H__4713B545_062B_11D2_B890_C54647D3D618__INCLUDED_)
