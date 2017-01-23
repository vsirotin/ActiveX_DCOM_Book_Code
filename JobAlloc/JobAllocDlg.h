// JobAllocDlg.h : header file
//

#if !defined(AFX_JOBALLOCDLG_H__43E33189_92FD_11D1_A249_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOCDLG_H__43E33189_92FD_11D1_A249_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CJobAllocDlg dialog

class CJobAllocDlg : public CDialog
{
// Construction
public:
	UINT GetNewJob(CString GetNewJob);
	CJobAllocDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CJobAllocDlg)
	enum { IDD = IDD_JOBALLOC_DIALOG };
	CString	m_strNewJob;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CJobAllocDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOCDLG_H__43E33189_92FD_11D1_A249_00A0C941DD59__INCLUDED_)
