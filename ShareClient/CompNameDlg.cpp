// CompNameDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShareClient.h"
#include "CompNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCompNameDlg dialog


CCompNameDlg::CCompNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCompNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCompNameDlg)
	m_strCompName = _T("");
	//}}AFX_DATA_INIT
}


void CCompNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCompNameDlg)
	DDX_Text(pDX, IDC_COMPUTER_NAME, m_strCompName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCompNameDlg, CDialog)
	//{{AFX_MSG_MAP(CCompNameDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCompNameDlg message handlers
