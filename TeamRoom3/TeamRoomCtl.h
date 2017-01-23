#if !defined(AFX_TEAMROOMCTL_H__D2DF0E74_DC6B_11D1_B890_83B4B7F80022__INCLUDED_)
#define AFX_TEAMROOMCTL_H__D2DF0E74_DC6B_11D1_B890_83B4B7F80022__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// TeamRoomCtl.h : Declaration of the CTeamRoomCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl : See TeamRoomCtl.cpp for implementation.

class CTeamRoomCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTeamRoomCtrl)

// Constructor
public:
	CTeamRoomCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTeamRoomCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual void OnAmbientPropertyChange(DISPID dispid);
	virtual void OnFontChanged();
	//}}AFX_VIRTUAL

//== attributes
public:

	CSize m_sizeInMetr;

	CPtrArray m_ptrarrRooms;

// Implementation

protected:
	
	~CTeamRoomCtrl();

	DECLARE_OLECREATE_EX(CTeamRoomCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CTeamRoomCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTeamRoomCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CTeamRoomCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CTeamRoomCtrl)
	afx_msg void OnRButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTeamRoomCtrl)
	afx_msg long GetArea();
	afx_msg short GetCountRoom();
	afx_msg short GetCountOrderAll();
	afx_msg float GetSumOrderAll();
	afx_msg BSTR GetInfoOrderAll();
	afx_msg BOOL Room(short x0, short y0, short x1, short y1, short xDoor, short yDoor);
	afx_msg BSTR GetName(short sIndex);
	afx_msg void SetName(short sIndex, LPCTSTR lpszNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTeamRoomCtrl)
	void FireNewOrder(short sIndex)
		{FireEvent(eventidNewOrder,EVENT_PARAM(VTS_I2), sIndex);}
	void FireClickInRoom(LPCTSTR lpstrName)
		{FireEvent(eventidClickInRoom,EVENT_PARAM(VTS_BSTR), lpstrName);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()


public:

	enum {
	//{{AFX_DISP_ID(CTeamRoomCtrl)
	dispidArea = 1L,
	dispidCountRoom = 2L,
	dispidCountOrderAll = 3L,
	dispidSumOrderAll = 4L,
	dispidInfoOrderAll = 5L,
	dispidRoom = 6L,
	dispidName = 7L,
	eventidNewOrder = 1L,
	eventidClickInRoom = 2L,
	//}}AFX_DISP_ID
	};
private:
	void SetSampleData();
	void SetRoom(const CPoint& p0, const CPoint& p1, const CPoint& pointDoor);

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMROOMCTL_H__D2DF0E74_DC6B_11D1_B890_83B4B7F80022__INCLUDED)
