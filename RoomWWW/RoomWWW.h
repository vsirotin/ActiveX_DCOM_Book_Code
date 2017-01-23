// RoomWWW.h : main header file for the ROOMWWW application
//

#if !defined(AFX_ROOMWWW_H__1FA04A05_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
#define AFX_ROOMWWW_H__1FA04A05_FA6E_11D1_B890_C384C30BFC13__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWApp:
// See RoomWWW.cpp for the implementation of this class
//

class CRoomWWWApp : public CWinApp
{
public:
	CRoomWWWApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomWWWApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRoomWWWApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMWWW_H__1FA04A05_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
