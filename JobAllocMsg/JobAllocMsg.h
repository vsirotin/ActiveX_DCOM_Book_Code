// JobAllocMsg.h : main header file for the JOBALLOCMSG application
//

#if !defined(AFX_JOBALLOCMSG_H__401F30A0_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOCMSG_H__401F30A0_93C7_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

class CJobAllocMsgView;
/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgApp:
// See JobAllocMsg.cpp for the implementation of this class
//

class CJobAllocMsgApp : public CWinApp
{
public:

	CJobAllocMsgView* m_pView;
	CJobAllocMsgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocMsgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CJobAllocMsgApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CJobAllocMsgApp theApp;

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOCMSG_H__401F30A0_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
