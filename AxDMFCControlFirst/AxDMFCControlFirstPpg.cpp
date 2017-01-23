// AxDMFCControlFirstPpg.cpp : Implementation of the CAxDMFCControlFirstPropPage property page class.

#include "stdafx.h"
#include "AxDMFCControlFirst.h"
#include "AxDMFCControlFirstPpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAxDMFCControlFirstPropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAxDMFCControlFirstPropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CAxDMFCControlFirstPropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAxDMFCControlFirstPropPage, "AXDMFCCONTROLFIRST.AxDMFCControlFirstPropPage.1",
	0xbd7b05fe, 0xd5dd, 0x11d1, 0xb8, 0x90, 0xb5, 0x2a, 0x27, 0xc4, 0x87, 0x24)


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstPropPage::CAxDMFCControlFirstPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CAxDMFCControlFirstPropPage

BOOL CAxDMFCControlFirstPropPage::CAxDMFCControlFirstPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_AXDMFCCONTROLFIRST_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstPropPage::CAxDMFCControlFirstPropPage - Constructor

CAxDMFCControlFirstPropPage::CAxDMFCControlFirstPropPage() :
	COlePropertyPage(IDD, IDS_AXDMFCCONTROLFIRST_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CAxDMFCControlFirstPropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstPropPage::DoDataExchange - Moves data between page and properties

void CAxDMFCControlFirstPropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CAxDMFCControlFirstPropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstPropPage message handlers
