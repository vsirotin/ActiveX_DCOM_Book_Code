// ShareClientDlg.h : header file
//

#if !defined(AFX_SHARECLIENTDLG_H__BCE3EBC9_13F3_11D2_B890_C88BEC79707C__INCLUDED_)
#define AFX_SHARECLIENTDLG_H__BCE3EBC9_13F3_11D2_B890_C88BEC79707C__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "DCOMShareServer.h"
/////////////////////////////////////////////////////////////////////////////
// CShareClientDlg dialog

#include "DCOMShareServer.h"
class CShareClientDlg : public CDialog
{
// Construction
public:
	void UpdateButton(BOOL bEnabled);
	void UpdateState(long lLastTrans);
	CShareClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShareClientDlg)
	enum { IDD = IDD_SHARECLIENT_DIALOG };
	CString	m_strCompInfo;
	CString	m_strTransInfo;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShareClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	IDCOMShareObj* m_pDCOMShareObj;
//	IDCOMShareEvents* m_pDCOMSchareObjEvents;
	DWORD m_dwCookie;

	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShareClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTransact();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHARECLIENTDLG_H__BCE3EBC9_13F3_11D2_B890_C88BEC79707C__INCLUDED_)
