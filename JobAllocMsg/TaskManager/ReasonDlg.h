#if !defined(AFX_REASONDLG_H__906D2303_93E4_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_REASONDLG_H__906D2303_93E4_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// ReasonDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CReasonDlg dialog

class CReasonDlg : public CDialog
{
// Construction
public:
	CReasonDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CReasonDlg)
	enum { IDD = IDD_DIALOG_REASON };
	CString	m_strReason;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReasonDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CReasonDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REASONDLG_H__906D2303_93E4_11D1_A24A_00A0C941DD59__INCLUDED_)
