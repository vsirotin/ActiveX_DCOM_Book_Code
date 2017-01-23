#if !defined(AFX_TEAMROOMPPG_H__D2DF0E76_DC6B_11D1_B890_83B4B7F80022__INCLUDED_)
#define AFX_TEAMROOMPPG_H__D2DF0E76_DC6B_11D1_B890_83B4B7F80022__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// TeamRoomPpg.h : Declaration of the CTeamRoomPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CTeamRoomPropPage : See TeamRoomPpg.cpp.cpp for implementation.

class CTeamRoomPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTeamRoomPropPage)
	DECLARE_OLECREATE_EX(CTeamRoomPropPage)

// Constructor
public:
	CTeamRoomPropPage();

// Dialog Data
	//{{AFX_DATA(CTeamRoomPropPage)
	enum { IDD = IDD_PROPPAGE_TEAMROOM };
	float	m_fArea;
	short	m_sCountRoom;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CTeamRoomPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMROOMPPG_H__D2DF0E76_DC6B_11D1_B890_83B4B7F80022__INCLUDED)
