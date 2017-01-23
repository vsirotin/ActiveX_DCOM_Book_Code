// TeamRoomCtl.cpp : Implementation of the CTeamRoomCtrl ActiveX Control class.

#include "stdafx.h"
#include "TeamRoom.h"
#include "TeamRoomCtl.h"
#include "TeamRoomPpg.h"
#include "Room.h"
#include "OrderDlg.h"
#include "TeamRoomDetails.h"
#include <objsafe.h>
#include "CompCat.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CTeamRoomCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CTeamRoomCtrl, COleControl)
	//{{AFX_MSG_MAP(CTeamRoomCtrl)
	ON_WM_RBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_EDIT, OnEdit)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CTeamRoomCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CTeamRoomCtrl)
	DISP_PROPERTY_EX(CTeamRoomCtrl, "Area", GetArea, SetNotSupported, VT_I4)
	DISP_PROPERTY_EX(CTeamRoomCtrl, "CountRoom", GetCountRoom, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CTeamRoomCtrl, "CountOrderAll", GetCountOrderAll, SetNotSupported, VT_I2)
	DISP_PROPERTY_EX(CTeamRoomCtrl, "SumOrderAll", GetSumOrderAll, SetNotSupported, VT_R4)
	DISP_PROPERTY_EX(CTeamRoomCtrl, "InfoOrderAll", GetInfoOrderAll, SetNotSupported, VT_BSTR)
	DISP_FUNCTION(CTeamRoomCtrl, "Room", Room, VT_BOOL, VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2 VTS_I2)
	DISP_PROPERTY_PARAM(CTeamRoomCtrl, "Name", GetName, SetName, VT_BSTR, VTS_I2)
	DISP_STOCKPROP_FONT()
	//}}AFX_DISPATCH_MAP
	DISP_FUNCTION_ID(CTeamRoomCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CTeamRoomCtrl, COleControl)
	//{{AFX_EVENT_MAP(CTeamRoomCtrl)
	EVENT_CUSTOM("NewOrder", FireNewOrder, VTS_I2)
	EVENT_STOCK_ERROREVENT()
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CTeamRoomCtrl, 3)
	PROPPAGEID(CTeamRoomPropPage::guid)
	PROPPAGEID(CTeamRoomDetails::guid)
	PROPPAGEID(CLSID_CFontPropPage)
END_PROPPAGEIDS(CTeamRoomCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CTeamRoomCtrl, "TEAMROOM.TeamRoomCtrl.1",
	0xd2df0e66, 0xdc6b, 0x11d1, 0xb8, 0x90, 0x83, 0xb4, 0xb7, 0xf8, 0, 0x22)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CTeamRoomCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DTeamRoom =
		{ 0xd2df0e64, 0xdc6b, 0x11d1, { 0xb8, 0x90, 0x83, 0xb4, 0xb7, 0xf8, 0, 0x22 } };
const IID BASED_CODE IID_DTeamRoomEvents =
		{ 0xd2df0e65, 0xdc6b, 0x11d1, { 0xb8, 0x90, 0x83, 0xb4, 0xb7, 0xf8, 0, 0x22 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwTeamRoomOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CTeamRoomCtrl, IDS_TEAMROOM, _dwTeamRoomOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::CTeamRoomCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CTeamRoomCtrl

BOOL CTeamRoomCtrl::CTeamRoomCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegInsertable | afxRegApartmentThreading to afxRegInsertable.

	HRESULT hr1 = CreateComponentCategory(CATID_SafeForScripting, 
			L"Steuerelement sicher für Scripting");

	HRESULT hr2 = CreateComponentCategory(CATID_SafeForInitializing, 
			L"Steuerelement sicher für Initialisierung von persistenten Daten");

	if (bRegister)
	{
		BOOL bRes = AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_TEAMROOM,
			IDB_TEAMROOM,
			afxRegInsertable | afxRegApartmentThreading,
			_dwTeamRoomOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);

		if (SUCCEEDED(hr1))
			RegisterCLSIDInCategory(m_clsid, CATID_SafeForScripting);

		if (SUCCEEDED(hr2))
			RegisterCLSIDInCategory(m_clsid, CATID_SafeForInitializing);

		return bRes;
	}
	else
	{
		if (SUCCEEDED(hr1))
			UnRegisterCLSIDInCategory(m_clsid, CATID_SafeForScripting);
	
		if (SUCCEEDED(hr2))
			UnRegisterCLSIDInCategory(m_clsid, CATID_SafeForInitializing);

		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
	}

}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::CTeamRoomCtrl - Constructor



CTeamRoomCtrl::CTeamRoomCtrl()
{
	InitializeIIDs(&IID_DTeamRoom, &IID_DTeamRoomEvents);

	// TODO: Initialize your control's instance data here.
	
	theApp.m_pTeamRoomCtrl = this;

}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::~CTeamRoomCtrl - Destructor

CTeamRoomCtrl::~CTeamRoomCtrl()
{
	// TODO: Cleanup your control's instance data here.

	int iSize = m_ptrarrRooms.GetSize();

	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		delete pRoom;
	}

	m_ptrarrRooms.RemoveAll();

}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::OnDraw - Drawing function

#define MARGIN_IN_PERCENT 0.05
void CTeamRoomCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	
	//== Mit der Hintergrundfarbe von Container Fenster zuerst ausfüllen
	
	CBrush brAmientBcgr(TranslateColor(AmbientBackColor()));
	CBrush* pBrushOld = pdc->SelectObject(&brAmientBcgr);
	CPoint point(0,0);
	pdc->RoundRect(rcBounds, point);
	pdc->SelectObject(pBrushOld);

	if((m_sizeInMetr.cx == 0) || (m_sizeInMetr.cy == 0))
	{
		CString strTmp;
		strTmp.Format("Falsche oder keine Geometrie");
		pdc->ExtTextOut(rcBounds.left, (rcBounds.top + rcBounds.bottom)/2, 
			ETO_CLIPPED|ETO_OPAQUE , rcBounds, strTmp, strTmp.GetLength(), NULL);

		return;
	}

	//Die Grenze mit der Strichlinie zeichnen 

	CRect rectTmp(rcBounds);
	rectTmp.DeflateRect((int)(rcBounds.Width() * MARGIN_IN_PERCENT), 
		(int)(rcBounds.Height() * MARGIN_IN_PERCENT));

	CPen penDash(PS_DASH, 1, RGB(200, 200, 200));
	CPen* penOld = pdc->SelectObject(&penDash);
	pdc->RoundRect(rectTmp, point);
	pdc->SelectObject(penOld);

	//== Die Zimmer zeichnen 
	int iSize = m_ptrarrRooms.GetSize();

	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		pRoom->Draw(pdc, rectTmp, m_sizeInMetr);
	}

}

/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::DoPropExchange - Persistence support

void CTeamRoomCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

	PX_Long(pPX, "X in Meter", m_sizeInMetr.cx, 0);
	PX_Long(pPX, "Y in Meter", m_sizeInMetr.cy, 0);	
	
	short sCountRoom;
	if((m_sizeInMetr.cx  == 0)&&(pPX->IsLoading()))
	{
		if(pPX->GetVersion()  == MAKELONG(0,1))
		{
			SetSampleData();
		}
	}
	else 
	{
		if(!pPX->IsLoading())
			sCountRoom = m_ptrarrRooms.GetSize();

		PX_Short(pPX, "Anzahl der Zimmer", sCountRoom, 0);

		for(short i = 0; i < sCountRoom; i++)
		{
			CRoom* pRoom;

			if(pPX->IsLoading())
			{
				pRoom = new CRoom;
				m_ptrarrRooms.Add((CObject*)pRoom);
			}
			else
				pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);

			ASSERT(pRoom);
			pRoom->DoPropExchange(pPX, (int)i);
		}
	}

//	m_countRoom = m_ptrarrRooms.GetSize();
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::OnResetState - Reset control to default state

void CTeamRoomCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.

}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl::AboutBox - Display an "About" box to the user

void CTeamRoomCtrl::AboutBox()
{
	CDialog dlgAbout(IDD_ABOUTBOX_TEAMROOM);
	dlgAbout.DoModal();
}


/////////////////////////////////////////////////////////////////////////////
// CTeamRoomCtrl message handlers


void CTeamRoomCtrl::SetRoom(const CPoint& p0, const CPoint& p1, const CPoint& pointDoor)
{
	CRoom* pRoom = new CRoom(p0, p1, pointDoor); 
	ASSERT(pRoom);
	
	m_ptrarrRooms.Add((CObject*)pRoom);

	m_sizeInMetr.cx = max(m_sizeInMetr.cx, p1.x);
	m_sizeInMetr.cy = max(m_sizeInMetr.cy, p0.y);

}

void CTeamRoomCtrl::SetSampleData() 
{

	SetRoom(CPoint(0, 30), CPoint(15, 20), CPoint(7, 20));
	SetRoom(CPoint(15, 30), CPoint(35, 20), CPoint(20, 20));
	SetRoom(CPoint(25, 20), CPoint(35, 0), CPoint(25, 10));
}



BOOL CTeamRoomCtrl::Room(short x0, short y0, short x1, short y1, short xDoor, short yDoor) 
{
	// TODO: Add your dispatch handler code here

	SetRoom(CPoint(x0, y0), CPoint(x1, y1), CPoint(xDoor, yDoor));
	InvalidateControl();

	return TRUE;
}

void CTeamRoomCtrl::OnAmbientPropertyChange(DISPID dispid) 
{
	// TODO: Add your specialized code here and/or call the base class

	InvalidateControl();
	
	COleControl::OnAmbientPropertyChange(dispid);
}

void CTeamRoomCtrl::OnFontChanged() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	InvalidateControl();

	COleControl::OnFontChanged();
}

long CTeamRoomCtrl::GetArea() 
{
	// TODO: Add your property handler here

	return m_sizeInMetr.cx * m_sizeInMetr.cy;
}

short CTeamRoomCtrl::GetCountRoom() 
{
	// TODO: Add your property handler here

	return m_ptrarrRooms.GetSize();
}

short CTeamRoomCtrl::GetCountOrderAll() 
{
	// TODO: Add your property handler here

	int iSize = m_ptrarrRooms.GetSize();

	short sCountAll = 0;
	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		sCountAll += pRoom->m_iCount;
	}
	return sCountAll;
}



float CTeamRoomCtrl::GetSumOrderAll() 
{
	// TODO: Add your property handler here

	int iSize = m_ptrarrRooms.GetSize();

	float fSumtAll = 0;
	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		fSumtAll += pRoom->m_fSum;
	}
	return fSumtAll;

}

BSTR CTeamRoomCtrl::GetInfoOrderAll() 
{
	CString strResult;
	// TODO: Add your property handler here

	int iSize = m_ptrarrRooms.GetSize();

	for(int i = 0; i < iSize; i++)
	{
		
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		CString strTmp("Bestellungen für Team ");
		strTmp += pRoom->m_strName + CString("\r\n");
		strResult += strTmp + pRoom->m_strInfo;
	}

	return strResult.AllocSysString();
}

BSTR CTeamRoomCtrl::GetName(short sIndex) 
{
	CString strResult;
	// TODO: Add your property handler here

	int iSize = m_ptrarrRooms.GetSize();
	if((0 <= sIndex)&&(sIndex < iSize))
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(sIndex);
		ASSERT(pRoom);
		strResult = CString(pRoom->m_strName);
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, "Ungültiger Index");
	}

	return strResult.AllocSysString();
}

void CTeamRoomCtrl::SetName(short sIndex, LPCTSTR lpszNewValue) 
{
	// TODO: Add your property handler here

	int iSize = m_ptrarrRooms.GetSize();
	if((0 <= sIndex)&&(sIndex < iSize))
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(sIndex);
		ASSERT(pRoom);
		pRoom->m_strName = CString(lpszNewValue);
		InvalidateControl();
	}
	else
	{
		ThrowError(CTL_E_INVALIDPROPERTYARRAYINDEX, "Ungültiger Index");
	}

	SetModifiedFlag();
}

void CTeamRoomCtrl::OnRButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CRect rectClient;
	GetClientRect(&rectClient);	

	rectClient.DeflateRect((int)(rectClient.Width() * MARGIN_IN_PERCENT), 
		(int)(rectClient.Height() * MARGIN_IN_PERCENT));

	int iSize = m_ptrarrRooms.GetSize();
	for(int i = 0; i < iSize; i++)
	{
		CRoom* pRoom = (CRoom*)m_ptrarrRooms.GetAt(i);
		ASSERT(pRoom);
		
		if(pRoom->HitTest(rectClient, m_sizeInMetr, point))
		{
	
			COrderDlg dlg;

			dlg.m_strName = pRoom->m_strName;
			dlg.m_uCount = (UINT)pRoom->m_iCount;
			dlg.m_dSum = pRoom->m_fSum;
			dlg.m_strInfoAll = pRoom->m_strInfo;
			if(dlg.DoModal() == IDOK)
			{
				pRoom->m_strName = dlg.m_strName;

				if((dlg.m_dPrice > 0)&&(!dlg.m_strInfo.IsEmpty()))
				{
					pRoom->m_iCount++;
					pRoom->m_fSum += (float)dlg.m_dPrice; 
					pRoom->m_strInfo += dlg.m_strInfo + CString("\r\n");
					FireNewOrder(i);
				}
				else
					FireError(0, "Falsche oder nicht vollständige Eingabe");

			}
			InvalidateControl();
			return;
		}
	}
	

	COleControl::OnRButtonDblClk(nFlags, point);
}
