// TeamRoomPpg.cpp : Implementation of the CTeamRoomPropPage property page class.

#include "stdafx.h"
#include "TeamRoom.h"
#include "TeamRoomPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTeamRoomPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTeamRoomPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CTeamRoomPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTeamRoomPropPage, "TEAMROOM.TeamRoomPropPage.1",
	0xd2df0e67, 0xdc6b, 0x11d1, 0xb8, 0x90, 0x83, 0xb4, 0xb7, 0xf8, 0, 0x22)


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomPropPage::CTeamRoomPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CTeamRoomPropPage

BOOL CTeamRoomPropPage::CTeamRoomPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_TEAMROOM_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomPropPage::CTeamRoomPropPage - Constructor

CTeamRoomPropPage::CTeamRoomPropPage() :
	COlePropertyPage(IDD, IDS_TEAMROOM_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CTeamRoomPropPage)
	m_fArea = 0.0f;
	m_sCountRoom = 0;
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomPropPage::DoDataExchange - Moves data between page and properties

void CTeamRoomPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CTeamRoomPropPage)
	DDP_Text(pDX, IDC_ROOM_AREA, m_fArea, _T("Area") );
	DDX_Text(pDX, IDC_ROOM_AREA, m_fArea);
	DDP_Text(pDX, IDC_ROOM_COUNT, m_sCountRoom, _T("CountRoom") );
	DDX_Text(pDX, IDC_ROOM_COUNT, m_sCountRoom);
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomPropPage message handlers
