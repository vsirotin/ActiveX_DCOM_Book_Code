// OrderDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TeamRoom.h"
#include "OrderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COrderDlg dialog


COrderDlg::COrderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(COrderDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(COrderDlg)
	m_uCount = 0;
	m_strInfo = _T("");
	m_strInfoAll = _T("");
	m_strName = _T("");
	m_dPrice = 0.0;
	m_dSum = 0.0;
	//}}AFX_DATA_INIT
}


void COrderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COrderDlg)
	DDX_Text(pDX, IDC_COUNT, m_uCount);
	DDX_Text(pDX, IDC_INFO, m_strInfo);
	DDX_Text(pDX, IDC_INFO_ALL, m_strInfoAll);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PRICE, m_dPrice);
	DDX_Text(pDX, IDC_SUM, m_dSum);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(COrderDlg, CDialog)
	//{{AFX_MSG_MAP(COrderDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COrderDlg message handlers
