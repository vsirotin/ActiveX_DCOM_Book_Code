// Chip.cpp: implementation of the CChip class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AxDATLCircuit.h"
#include "Chip.h"
#include <string.h>


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////


CChip::CChip()
{

}

CChip::CChip(short x0, short y0, short x1, short y1, char* strName, 
		LINE* pLine1, LINE* pLine2, LINE* pLine3, LINE* pLine4)
{
	m_sCount = 0;

	left = x0;
	top = y0;
	right = x1;
	bottom = y1;

	::strncpy(m_strName, strName, 10);
	m_uCountContact = 0;

	if(pLine1 != NULL)
	{
		m_contact[0] = *pLine1;
		m_uCountContact++;

	}

	if(pLine2 != NULL)
	{
		m_contact[1] = *pLine2;
		m_uCountContact++;

	}

	if(pLine3 != NULL)
	{
		m_contact[2] = *pLine3;
		m_uCountContact++;

	}

	if(pLine4 != NULL)
	{
		m_contact[3] = *pLine4;
		m_uCountContact++;

	}

}

CChip::~CChip()
{

}


bool CChip::Draw(ATL_DRAWINFO& di, const RECT& rcCircuit)
{

	long lCircWidth = rcCircuit.right - rcCircuit.left;
	long lCircHeight = rcCircuit.top - rcCircuit.bottom;

	if((lCircWidth <= 0)||(lCircHeight <= 0))
		return false;


	RECT rcBound = *(RECT*)di.prcBounds;
	long lBoundWidth = rcBound.right - rcBound.left;
	long lBoundHeight = rcBound.bottom - rcBound.top;

	if((lBoundWidth <= 0)||(lBoundHeight <= 0))
		return false;


	double dMasX	= (double)lBoundWidth/lCircWidth;
	double dMasY	= - (double)lBoundHeight/lCircHeight;


	RECT rectTmp;

	rectTmp.left	= (int)(left * dMasX) + rcBound.left;
	rectTmp.top		= (int)(top * dMasY) + rcBound.bottom;
	rectTmp.right	= (int)(right * dMasX) + rcBound.left;
	rectTmp.bottom	= (int)(bottom * dMasY) + rcBound.bottom;


	//== Streichen

	COLORREF colForgr;
	
	if(m_sCount < 0)
		colForgr = RGB(255, 0, 0);
	else if(m_sCount == 0)
		colForgr = RGB(255, 255, 0);
	else
		colForgr = RGB(0, 255, 0);
	
	HBRUSH hOldBrush, hBrush;
	hBrush = ::CreateSolidBrush(colForgr);
	hOldBrush = (HBRUSH)::SelectObject(di.hdcDraw, hBrush);
	::Rectangle(di.hdcDraw, rectTmp.left, rectTmp.top, rectTmp.right, rectTmp.bottom);
	::SelectObject(di.hdcDraw, hOldBrush);

//== Kontakten


	for(UINT i =0; i < m_uCountContact; i++)
	{	
		LINE line = m_contact[i];

		int x0	= (int)(line.p0.x * dMasX) + rcBound.left;
		int y0	= (int)(line.p0.y * dMasY) + rcBound.bottom;
		int x1	= (int)(line.p1.x * dMasX) + rcBound.left;
		int y1	= (int)(line.p1.y * dMasY) + rcBound.bottom;

		::MoveToEx(di.hdcDraw, x0, y0, NULL);
		::LineTo(di.hdcDraw, x1, y1);
	}

//== Name
	::SetBkMode(di.hdcDraw, TRANSPARENT);

	rectTmp.left += (rectTmp.right - rectTmp.left)/10;
	::DrawText(di.hdcDraw, m_strName, -1, &rectTmp, DT_VCENTER | DT_SINGLELINE);

	return true;
}

bool CChip::HitTestDraw(WORD xPos, WORD yPos, const RECT& rcClientWnd, const RECT& rcCircuit)
{
	long lCircWidth = rcCircuit.right - rcCircuit.left;
	long lCircHeight = rcCircuit.top - rcCircuit.bottom;

	if((lCircWidth <= 0)||(lCircHeight <= 0))
		return false;

	long lBoundWidth = rcClientWnd.right - rcClientWnd.left;
	long lBoundHeight = rcClientWnd.bottom - rcClientWnd.top;

	if((lBoundWidth <= 0)||(lBoundHeight <= 0))
		return false;


	double dMasX	= (double)lBoundWidth/lCircWidth;
	double dMasY	= - (double)lBoundHeight/lCircHeight;


	RECT rectTmp;

	rectTmp.left	= (int)(left * dMasX) + rcClientWnd.left;
	rectTmp.top		= (int)(top * dMasY) + rcClientWnd.bottom;
	rectTmp.right	= (int)(right * dMasX) + rcClientWnd.left;
	rectTmp.bottom	= (int)(bottom * dMasY) + rcClientWnd.bottom;

	if((rectTmp.left <= xPos)&&(xPos <= rectTmp.right)
		&&(rectTmp.top <= yPos)&&(yPos <= rectTmp.bottom))
		return true;

	return false;
}