// ReasonDlg1.cpp : implementation file
//

#include "stdafx.h"
#include "TaskManagerCOM.h"
#include "ReasonDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReasonDlg dialog


CReasonDlg::CReasonDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CReasonDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReasonDlg)
	m_strReason = _T("");
	//}}AFX_DATA_INIT
}


void CReasonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReasonDlg)
	DDX_Text(pDX, IDC_EDIT_REASON, m_strReason);
	DDV_MaxChars(pDX, m_strReason, 100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReasonDlg, CDialog)
	//{{AFX_MSG_MAP(CReasonDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReasonDlg message handlers
