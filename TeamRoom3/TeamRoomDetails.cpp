// TeamRoomDetails.cpp : implementation file
//

#include "stdafx.h"
#include "TeamRoom.h"
#include "TeamRoomDetails.h"
#include "TeamRoomCtl.h"
#include "Room.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails dialog

IMPLEMENT_DYNCREATE(CTeamRoomDetails, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTeamRoomDetails, COlePropertyPage)
	//{{AFX_MSG_MAP(CTeamRoomDetails)
	ON_WM_PAINT()
	ON_CBN_SELCHANGE(IDC_TEAMS, OnSelchangeTeams)
	ON_BN_CLICKED(IDC_CHANGE_CRL, OnChangeCrl)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

// {215ED3D5-E4C6-11D1-A2AC-00A0C941DD59}
IMPLEMENT_OLECREATE_EX(CTeamRoomDetails, "TeamRoom.CTeamRoomDetails",
	0x215ed3d5, 0xe4c6, 0x11d1, 0xa2, 0xac, 0x0, 0xa0, 0xc9, 0x41, 0xdd, 0x59)


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails::CTeamRoomDetailsFactory::UpdateRegistry -
// Adds or removes system registry entries for CTeamRoomDetails

BOOL CTeamRoomDetails::CTeamRoomDetailsFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Define string resource for page type; replace '0' below with ID.

	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(), 
			m_clsid, IDD_PROPPAGE_TEAMROOM1);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails::CTeamRoomDetails - Constructor

// TODO: Define string resource for page caption; replace '0' below with ID.

CTeamRoomDetails::CTeamRoomDetails() :
	COlePropertyPage(IDD, IDD_PROPPAGE_TEAMROOM1_CAPTION)
{
	//{{AFX_DATA_INIT(CTeamRoomDetails)
	m_iCurCount = 0;
	m_fCurSum = 0.0f;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails::DoDataExchange - Moves data between page and properties

void CTeamRoomDetails::DoDataExchange(CDataExchange* pDX)
{
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//{{AFX_DATA_MAP(CTeamRoomDetails)
	DDX_Control(pDX, IDC_TEAMS, m_comboxRoomList);
	DDX_Text(pDX, IDC_ORD_COUNT, m_iCurCount);
	DDX_Text(pDX, IDC_ORD_SUM, m_fCurSum);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomDetails message handlers

BOOL CTeamRoomDetails::OnInitDialog() 
{
	COlePropertyPage::OnInitDialog();
	
	// TODO: Add extra initialization here

	int iSize = theApp.m_pTeamRoomCtrl->m_ptrarrRooms.GetSize();
	
	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)theApp.m_pTeamRoomCtrl->m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		
		m_comboxRoomList.AddString(pRoom->m_strName);
	}
	SetParamsOfRoom(0); 
		
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CTeamRoomDetails::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	
	CWnd* pWnd = GetDlgItem(IDC_CHANGE_CRL);
	ASSERT(pWnd);
	
	//== Koordinaten rechnen
	CRect rcClient;
	pWnd->GetWindowRect(&rcClient);
	ScreenToClient(rcClient);
	
	long lHeight = rcClient.bottom - rcClient.top;
	rcClient.top -= (long)(lHeight*1.2);
	rcClient.bottom -= (long)(lHeight*1.2);

	//== Farbe für aktuelles Zimmer 
	CPoint point(5,5);
	CBrush brush(m_clrCurrColor); 
	CBrush* pOldBrus = dc.SelectObject(&brush); 
	dc.RoundRect(rcClient, point);
	dc.SelectObject(pOldBrus);
	
	// Do not call COlePropertyPage::OnPaint() for painting messages
}

void CTeamRoomDetails::OnSelchangeTeams() 
{
	// TODO: Add your control notification handler code here
	int iInd = m_comboxRoomList.GetCurSel();
	SetParamsOfRoom(iInd);
}

void CTeamRoomDetails::OnChangeCrl() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	if(dlg.DoModal() == IDOK)
	{
		m_clrCurrColor = dlg.GetColor();
		
		CRoom* pRoom = (CRoom*)theApp.m_pTeamRoomCtrl->m_ptrarrRooms.GetAt(m_iCurrRoom);
		ASSERT(pRoom);
		pRoom->SetColor(m_clrCurrColor);
		Invalidate();
		theApp.m_pTeamRoomCtrl->InvalidateControl();
		
	}
}

void CTeamRoomDetails::SetParamsOfRoom(int iIndex) 
{
	int iSize = theApp.m_pTeamRoomCtrl->m_ptrarrRooms.GetSize();
	
	if((0 > iIndex)||(iIndex > iSize))
	{
		TRACE("Falsche iIndex in CTeamRoomDetails::SetParamsOfRoom\n");
		return;
	}
	
	m_iCurrRoom = iIndex;
	CRoom* pRoom = (CRoom*)theApp.m_pTeamRoomCtrl->m_ptrarrRooms.GetAt(m_iCurrRoom);
	ASSERT(pRoom);

	m_comboxRoomList.SetCurSel(m_iCurrRoom);

	m_clrCurrColor = pRoom->GetColor();

	m_iCurCount = pRoom->m_iCount;
	m_fCurSum = pRoom->m_fSum;

	UpdateData(FALSE);
	Invalidate();
	

}
