// AxDMFCControlFirstCtl.cpp : Implementation of the CAxDMFCControlFirstCtrl ActiveX Control class.

#include "stdafx.h"
#include "AxDMFCControlFirst.h"
#include "AxDMFCControlFirstCtl.h"
#include "AxDMFCControlFirstPpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CAxDMFCControlFirstCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CAxDMFCControlFirstCtrl, COleControl)
	//{{AFX_MSG_MAP(CAxDMFCControlFirstCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CAxDMFCControlFirstCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CAxDMFCControlFirstCtrl)
	DISP_PROPERTY_EX(CAxDMFCControlFirstCtrl, "xRes", GetXRes, SetXRes, VT_I2)
	DISP_PROPERTY_EX(CAxDMFCControlFirstCtrl, "yRes", GetYRes, SetYRes, VT_I2)
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CAxDMFCControlFirstCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CAxDMFCControlFirstCtrl, COleControl)
	//{{AFX_EVENT_MAP(CAxDMFCControlFirstCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CAxDMFCControlFirstCtrl, 1)
	PROPPAGEID(CAxDMFCControlFirstPropPage::guid)
END_PROPPAGEIDS(CAxDMFCControlFirstCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CAxDMFCControlFirstCtrl, "AXDMFCCONTROLFIRST.AxDMFCControlFirstCtrl.1",
	0xbd7b05fd, 0xd5dd, 0x11d1, 0xb8, 0x90, 0xb5, 0x2a, 0x27, 0xc4, 0x87, 0x24)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CAxDMFCControlFirstCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DAxDMFCControlFirst =
		{ 0xbd7b05fb, 0xd5dd, 0x11d1, { 0xb8, 0x90, 0xb5, 0x2a, 0x27, 0xc4, 0x87, 0x24 } };
const IID BASED_CODE IID_DAxDMFCControlFirstEvents =
		{ 0xbd7b05fc, 0xd5dd, 0x11d1, { 0xb8, 0x90, 0xb5, 0x2a, 0x27, 0xc4, 0x87, 0x24 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwAxDMFCControlFirstOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CAxDMFCControlFirstCtrl, IDS_AXDMFCCONTROLFIRST, _dwAxDMFCControlFirstOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::CAxDMFCControlFirstCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CAxDMFCControlFirstCtrl

BOOL CAxDMFCControlFirstCtrl::CAxDMFCControlFirstCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegInsertable | afxRegApartmentThreading to afxRegInsertable.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_AXDMFCCONTROLFIRST,
			IDB_AXDMFCCONTROLFIRST,
			afxRegInsertable | afxRegApartmentThreading,
			_dwAxDMFCControlFirstOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::CAxDMFCControlFirstCtrl - Constructor

CAxDMFCControlFirstCtrl::CAxDMFCControlFirstCtrl()
{
	InitializeIIDs(&IID_DAxDMFCControlFirst, &IID_DAxDMFCControlFirstEvents);

	// TODO: Initialize your control's instance data here.

	m_xRes = ::GetSystemMetrics(SM_CXSCREEN);
	m_yRes = ::GetSystemMetrics(SM_CYSCREEN);
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::~CAxDMFCControlFirstCtrl - Destructor

CAxDMFCControlFirstCtrl::~CAxDMFCControlFirstCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::OnDraw - Drawing function

void CAxDMFCControlFirstCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);

	CString strTmp;
	strTmp.Format("%d * %d", m_xRes, m_yRes);
	pdc->ExtTextOut(rcBounds.left, (rcBounds.top + rcBounds.bottom)/2, 
			ETO_CLIPPED, rcBounds, strTmp, strTmp.GetLength(), NULL);

}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::DoPropExchange - Persistence support

void CAxDMFCControlFirstCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::OnResetState - Reset control to default state

void CAxDMFCControlFirstCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl::AboutBox - Display an "About" box to the user

void CAxDMFCControlFirstCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_AXDMFCCONTROLFIRST);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl message handlers

short CAxDMFCControlFirstCtrl::GetXRes() 
{
	// TODO: Add your property handler here

	return m_xRes;
}

void CAxDMFCControlFirstCtrl::SetXRes(short nNewValue) 
{
	// TODO: Add your property handler here

	SetModifiedFlag();
}

short CAxDMFCControlFirstCtrl::GetYRes() 
{
	// TODO: Add your property handler here

	return m_yRes;
}

void CAxDMFCControlFirstCtrl::SetYRes(short nNewValue) 
{
	// TODO: Add your property handler here

	SetModifiedFlag();
}
