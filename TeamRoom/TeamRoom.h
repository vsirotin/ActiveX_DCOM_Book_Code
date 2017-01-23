#if !defined(AFX_TEAMROOM_H__D2DF0E6C_DC6B_11D1_B890_83B4B7F80022__INCLUDED_)
#define AFX_TEAMROOM_H__D2DF0E6C_DC6B_11D1_B890_83B4B7F80022__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// TeamRoom.h : main header file for TEAMROOM.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTeamRoomApp : See TeamRoom.cpp for implementation.

class CTeamRoomCtrl;
class CTeamRoomApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();

	CTeamRoomCtrl* m_pTeamRoomCtrl;
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

extern CTeamRoomApp NEAR theApp;

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMROOM_H__D2DF0E6C_DC6B_11D1_B890_83B4B7F80022__INCLUDED)
