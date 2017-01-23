// TaskStartDlg.h : header file
//

#if !defined(AFX_TASKSTARTDLG_H__4483FC28_911B_11D1_AD23_444553540000__INCLUDED_)
#define AFX_TASKSTARTDLG_H__4483FC28_911B_11D1_AD23_444553540000__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CTaskStartDlg dialog

class CTaskStartDlg : public CDialog
{
// Construction
public:
	CTaskStartDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTaskStartDlg)
	enum { IDD = IDD_TASKSTART_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskStartDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTaskStartDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnNewTask();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKSTARTDLG_H__4483FC28_911B_11D1_AD23_444553540000__INCLUDED_)
