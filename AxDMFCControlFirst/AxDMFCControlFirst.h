#if !defined(AFX_AXDMFCCONTROLFIRST_H__BD7B0603_D5DD_11D1_B890_B52A27C48724__INCLUDED_)
#define AFX_AXDMFCCONTROLFIRST_H__BD7B0603_D5DD_11D1_B890_B52A27C48724__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// AxDMFCControlFirst.h : main header file for AXDMFCCONTROLFIRST.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstApp : See AxDMFCControlFirst.cpp for implementation.

class CAxDMFCControlFirstApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXDMFCCONTROLFIRST_H__BD7B0603_D5DD_11D1_B890_B52A27C48724__INCLUDED)
