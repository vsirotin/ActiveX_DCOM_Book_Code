// ShareClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ShareClient.h"
#include "ShareClientDlg.h"
#include "CompNameDlg.h"
#include "ShareEvents.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShareClientDlg dialog

CShareClientDlg::CShareClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShareClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShareClientDlg)
	m_strCompInfo = _T("");
	m_strTransInfo = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CShareClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShareClientDlg)
	DDX_Text(pDX, IDC_COMP_INFO, m_strCompInfo);
	DDX_Text(pDX, IDC_TRANS_INFO, m_strTransInfo);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShareClientDlg, CDialog)
	//{{AFX_MSG_MAP(CShareClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_TRANSACT, OnTransact)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShareClientDlg message handlers

BOOL CShareClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	CCompNameDlg dlg;
	dlg.DoModal();
	
	CString strComputerName = dlg.m_strCompName;

	if(dlg.m_strCompName.IsEmpty())
	{
		char cComputerName[100];
		DWORD dwSize = 100;
	
		::GetComputerName(cComputerName, &dwSize);
		strComputerName = CString(cComputerName);
	}

	
	COSERVERINFO serverinfo;
	serverinfo.dwReserved1 = 0;
	serverinfo.dwReserved2 = 0;
	serverinfo.pwszName = strComputerName.AllocSysString();
	serverinfo.pAuthInfo = NULL;


	MULTI_QI qi = {&IID_IDCOMShareObj, NULL, 0};

	HRESULT hr = ::CoCreateInstanceEx(CLSID_DCOMShareObj, NULL,
		CLSCTX_LOCAL_SERVER | CLSCTX_REMOTE_SERVER, &serverinfo, 1, &qi);

	::SysFreeString(serverinfo.pwszName);
	
	if(FAILED(hr) || FAILED(qi.hr))
	{
		m_strTransInfo.Format("hr = 0x%x qi.h = 0x%x", hr, qi.hr);
		m_strCompInfo.Format("Server %s nicht gefunden", strComputerName);
		m_pDCOMShareObj = NULL;
		UpdateButton(FALSE);
		UpdateData(FALSE);
		return FALSE;
	}
	else
	{
	
		m_pDCOMShareObj = (IDCOMShareObj*)qi.pItf;

		CComObject<CShareEvents>* pSvr;
		CComObject<CShareEvents>::CreateInstance(&pSvr);
		m_dwCookie = 123;
		hr = AtlAdvise(m_pDCOMShareObj, pSvr->GetUnknown(), IID_IDCOMShareEvents, &m_dwCookie);
		
		if(FAILED(hr))
		{
			m_strCompInfo.Format("Kann nicht Ereignisschnittstelle Erzeugen hr = 0x%x", hr);
			m_pDCOMShareObj = NULL;
			UpdateButton(FALSE);
			UpdateData(FALSE);
			return FALSE;
		}
		else
		{
			m_strCompInfo.Format("Server auf Computer %s gestartet", strComputerName);
			UpdateData(FALSE);
		}
	
	}
	
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CShareClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CShareClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CShareClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CShareClientDlg::UpdateState(long lLastTrans)
{
	if(lLastTrans < 0)
	{
		UpdateButton(FALSE);
		m_strTransInfo.Format("Ressource ist nict erreichbar");
	}
	else
	{
		UpdateButton(TRUE);
		m_strTransInfo.Format("Letzte bekannte Transaktion: N %ld", lLastTrans);
	}
	UpdateData(FALSE);
}

void CShareClientDlg::OnTransact() 
{
	// TODO: Add your control notification handler code here
	if(m_pDCOMShareObj == NULL)
		return;

	UpdateButton(FALSE);
	HRESULT hr = m_pDCOMShareObj->AddValue();

	if(FAILED(hr))
	{
		m_strTransInfo.Format("Ressource ist nict erreichbar hr = 0x%x ", hr);
	}
	else
	{
		m_strTransInfo.Format("Last Transaktion OK");
		UpdateButton(TRUE);
	}
	UpdateData(FALSE);
}

void CShareClientDlg::UpdateButton(BOOL bEnabled)
{
	CWnd* pWnd = GetDlgItem(IDC_TRANSACT);

	ASSERT(pWnd != NULL);

	pWnd->EnableWindow(bEnabled);

}

void CShareClientDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	
	if(m_pDCOMShareObj != NULL)
	{
		AtlUnadvise(m_pDCOMShareObj, IID_IDCOMShareEvents, m_dwCookie);
		m_pDCOMShareObj->Release();
	}
}
