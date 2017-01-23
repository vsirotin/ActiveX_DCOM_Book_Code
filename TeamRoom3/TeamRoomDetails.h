#if !defined(AFX_TEAMROOMDETAILS_H__215ED3D6_E4C6_11D1_A2AC_00A0C941DD59__INCLUDED_)
#define AFX_TEAMROOMDETAILS_H__215ED3D6_E4C6_11D1_A2AC_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// TeamRoomDetails.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails : Property page dialog

class CTeamRoomDetails : public COlePropertyPage
{
	DECLARE_DYNCREATE(CTeamRoomDetails)
	DECLARE_OLECREATE_EX(CTeamRoomDetails)

// Constructors
public:
	CTeamRoomDetails();

// Dialog Data
	//{{AFX_DATA(CTeamRoomDetails)
	enum { IDD = IDD_PROPPAGE_TEAMROOM1 };
	CComboBox	m_comboxRoomList;
	int		m_iCurCount;
	float	m_fCurSum;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);        // DDX/DDV support

	void SetParamsOfRoom(int iIndex); 

// Message maps
protected:
	//{{AFX_MSG(CTeamRoomDetails)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnSelchangeTeams();
	afx_msg void OnChangeCrl();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

//== attributes
public:
	COLORREF m_clrCurrColor;
	int m_iCurrRoom;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEAMROOMDETAILS_H__215ED3D6_E4C6_11D1_A2AC_00A0C941DD59__INCLUDED_)
