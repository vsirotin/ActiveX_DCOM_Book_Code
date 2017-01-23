// Room.cpp: implementation of the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "TeamRoom.h"
#include "Room.h"
#include "TeamRoomCtl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRoom::CRoom()
{

}

UINT uN = 1;
CRoom::CRoom(const CPoint& p0, const CPoint& p1, const CPoint& pointDoor)
{
	m_p0 = p0;
	m_p1 = p1;
	m_pDoor = pointDoor;

	m_iCount = 0;
	m_fSum = 0;
	m_color = RGB(0, 255,5);
	m_strName.Format("%d", uN++);

}

CRoom::~CRoom()
{

}

void CRoom::SetColor(const COLORREF& color)
{
	m_color = color;
}

COLORREF CRoom::GetColor()
{
	return m_color;
}

void CRoom::Draw(CDC* pdc, const CRect& rcBound, const CSize& sizeInMetr)
{
	ASSERT(sizeInMetr.cx > 0);
	ASSERT(sizeInMetr.cy > 0);

	CRect rectTmp;


	double dMasX	= (double)rcBound.Width()/sizeInMetr.cx;
	double dMasY	= - (double)rcBound.Height()/sizeInMetr.cy;

	rectTmp.left	= (int)(m_p0.x * dMasX) + rcBound.left;
	rectTmp.top		= (int)(m_p0.y * dMasY) + rcBound.bottom;
	rectTmp.right	= (int)(m_p1.x * dMasX) + rcBound.left;
	rectTmp.bottom	= (int)(m_p1.y * dMasY) + rcBound.bottom;


	CPoint pointDoorCentre;
	pointDoorCentre.x	= (int)(m_pDoor.x * dMasX) + rcBound.left;
	pointDoorCentre.y	= (int)(m_pDoor.y * dMasY) + rcBound.bottom;

	//== Streichen
	CPoint point(0,0);

	pdc->SetBkColor(m_color);

	CBrush brush(m_color); 
	CBrush* pOldBrus = pdc->SelectObject(&brush); 
	pdc->RoundRect(rectTmp, point);
	pdc->SelectObject(pOldBrus);

	//Name zeichnen
	
	CFont* pOldFont;
	pOldFont = theApp.m_pTeamRoomCtrl->SelectStockFont(pdc);
	pdc->SetBkMode(TRANSPARENT);
	pdc->ExtTextOut((rectTmp.left + rectTmp.right)/2, 
		(rectTmp.top + rectTmp.bottom)/2, 
		ETO_CLIPPED, rectTmp, m_strName, m_strName.GetLength(), NULL);
	pdc->SelectObject(pOldFont);

	//== Grenze zeichnen
	CPen pen(PS_SOLID, 1, RGB(0, 0, 0));
	CPen* penOld = pdc->SelectObject(&pen);

	//== Tür zeichnen
	int d = (int)rcBound.Width()/100 + 2;

	CPoint p0, p1, p2, p3;
	
	p0 = CPoint(pointDoorCentre.x - d, pointDoorCentre.y - d);
	pdc->MoveTo(p0);

	p1 = CPoint(pointDoorCentre.x + d, pointDoorCentre.y + d);
	pdc->LineTo(p1);

	p2 = CPoint(pointDoorCentre.x - d, pointDoorCentre.y + d);
	pdc->MoveTo(p2);

	p3 = CPoint(pointDoorCentre.x + d, pointDoorCentre.y - d);
	pdc->LineTo(p3);

	pdc->SelectObject(penOld);
}

bool CRoom::HitTest(const CRect& rectClient, const CSize& sizeInMetr, const CPoint& point)
{
	ASSERT(sizeInMetr.cx > 0);
	ASSERT(sizeInMetr.cy > 0);

	double dMasX	= (double)rectClient.Width()/sizeInMetr.cx;
	double dMasY	= - (double)rectClient.Height()/sizeInMetr.cy;

	int x0	= (int)(m_p0.x * dMasX) + rectClient.left;
	int y0	= (int)(m_p0.y * dMasY) + rectClient.bottom;
	int x1	= (int)(m_p1.x * dMasX) + rectClient.left;
	int y1	= (int)(m_p1.y * dMasY) + rectClient.bottom;

	int x	= point.x;
	int y	= point.y;


	if((x0 <= x)&&(x <= x1)&&(y0 <= y)&&(y <= y1))
		return true;

	return false;
}


void CRoom::DoPropExchange(CPropExchange* pPX, int i)
{
	PX_Long(pPX, MakeUName(i, "P0.X in Meter"), m_p0.x);
	PX_Long(pPX, MakeUName(i,"P0.Y in Meter"), m_p0.y);

	PX_Long(pPX, MakeUName(i,"P1.X in Meter"), m_p1.x);
	PX_Long(pPX, MakeUName(i,"P1.Y in Meter"), m_p1.y);

	PX_Long(pPX, MakeUName(i,"PDoor.X in Meter"), m_pDoor.x);
	PX_Long(pPX, MakeUName(i,"PDoor.Y in Meter"), m_pDoor.y);

	PX_Color(pPX, MakeUName(i,"Farbe"), m_color);
	
	PX_String(pPX, MakeUName(i,"Name"), m_strName);
	PX_String(pPX, MakeUName(i,"Info"), m_strInfo);
	PX_Float(pPX, MakeUName(i,"Summe"), m_fSum);
	PX_Short(pPX, MakeUName(i,"Anzahl der Bestellungen"), m_iCount);
}

CString CRoom::MakeUName(int i, LPCSTR strName)
{
	CString strTmp;
	strTmp.Format("%d:%s", i, strName);
	return strTmp;
}

