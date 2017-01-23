#if !defined(AFX_ORDERDLG_H__76A3E4C1_E2B7_11D1_B890_D546151A792E__INCLUDED_)
#define AFX_ORDERDLG_H__76A3E4C1_E2B7_11D1_B890_D546151A792E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// OrderDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COrderDlg dialog

class COrderDlg : public CDialog
{
// Construction
public:
	COrderDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(COrderDlg)
	enum { IDD = IDD_DIALOG_ORDER };
	UINT	m_uCount;
	CString	m_strInfo;
	CString	m_strInfoAll;
	CString	m_strName;
	double	m_dPrice;
	double	m_dSum;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COrderDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COrderDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ORDERDLG_H__76A3E4C1_E2B7_11D1_B890_D546151A792E__INCLUDED_)
