#if !defined(AFX_COMPNAMEDLG_H__1B871CC1_0A1B_11D2_B890_917D2ACFB85F__INCLUDED_)
#define AFX_COMPNAMEDLG_H__1B871CC1_0A1B_11D2_B890_917D2ACFB85F__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CompNameDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCompNameDlg dialog

class CCompNameDlg : public CDialog
{
// Construction
public:
	CCompNameDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCompNameDlg)
	enum { IDD = IDD_DIALOG_COMP_NAME };
	CString	m_strCompName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCompNameDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCompNameDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMPNAMEDLG_H__1B871CC1_0A1B_11D2_B890_917D2ACFB85F__INCLUDED_)
