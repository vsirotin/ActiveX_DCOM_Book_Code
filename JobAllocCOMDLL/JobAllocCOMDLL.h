// JobAllocCOMDLL.h : main header file for the JOBALLOCCOMDLL DLL
//

#if !defined(AFX_JOBALLOCCOMDLL_H__88A3F9FB_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOCCOMDLL_H__88A3F9FB_A12F_11D1_A259_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CJobAllocCOMDLLApp
// See JobAllocCOMDLL.cpp for the implementation of this class
//

class CJobAllocCOMDLLApp : public CWinApp
{
public:
//	UINT m_uRefCount;
	CJobAllocCOMDLLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocCOMDLLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CJobAllocCOMDLLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern UINT g_uObjCount;
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOCCOMDLL_H__88A3F9FB_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
