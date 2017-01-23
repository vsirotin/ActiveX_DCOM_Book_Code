// IntCircuitCtl.cpp : Implementation of CIntCircuitCtl
#include "stdafx.h"
#include "AxDATLCircuit.h"
#include "IntCircuitCtl.h"
#include "Chip.h"
#include <string.h>
#include "ChoiceDlg.h"

/////////////////////////////////////////////////////////////////////////////
// CIntCircuitCtl

STDMETHODIMP CIntCircuitCtl::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIntCircuitCtl,
	};
	for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

HRESULT CIntCircuitCtl::OnDraw(ATL_DRAWINFO& di)
{
	//== Konvertierung OLE Color in COLORREF
	COLORREF colBackg;
	OleTranslateColor(m_clrBackColor, NULL, &colBackg);

	//== Neue Malinstrumente einstellen
	HBRUSH hOldBrush, hBrush;
	hBrush = ::CreateSolidBrush(colBackg);
	hOldBrush = (HBRUSH)::SelectObject(di.hdcDraw, hBrush);

	HPEN hOldPen, hPen;
	hPen = (HPEN)::GetStockObject(BLACK_PEN);
	hOldPen = (HPEN)::SelectObject(di.hdcDraw, hPen);
	
	//== Rechtecke zeichnen
	RECT& rc = *(RECT*)di.prcBounds;
	::Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

	//== Alte Malinstrumente wiederherstellen

	::SelectObject(di.hdcDraw, hOldBrush);
	::SelectObject(di.hdcDraw, hOldPen);


	for(UINT i= 0; i < m_uCountChip; i++)
	{
		m_pChipsArr[i]->Draw(di, m_rectGabarit);

	}

	return S_OK;
}


void CIntCircuitCtl::SetSampleData()
{

	m_uCountChip = 0;

	LINE line1, line2, line3, line4;

//== Chip 1
	line1.p0.x = line1.p1.x = 15;
	line1.p0.y = 40;
	line1.p1.y = 30;

	line2.p0.x = line2.p1.x = 20;
	line2.p0.y = 40;
	line2.p1.y = 30;

	line3.p0.x = line3.p1.x = 25;
	line3.p0.y = 40;
	line3.p1.y = 30;

	line4.p0.y = line4.p1.y = 55;
	line4.p0.x = 30;
	line4.p1.x = 40;


	CChip* pNewChip = new CChip(5, 65, 30, 40, "AE120", &line1, &line2, &line3, &line4);

	pNewChip->m_sCount = 2;

	m_pChipsArr[m_uCountChip++] = pNewChip;

	UpdateGabRect(*pNewChip);

//== Chip 2
	line1.p0.x = line1.p1.x = 45;
	line1.p0.y = 45;
	line1.p1.y = 30;

	line2.p0.x = line2.p1.x = 55;
	line2.p0.y = 45;
	line2.p1.y = 30;


	pNewChip = new CChip(40, 60, 65, 45, "CN14", &line1, &line2);

	pNewChip->m_sCount = 0;

	m_pChipsArr[m_uCountChip++] = pNewChip;

	UpdateGabRect(*pNewChip);

//== Chip 3
	line1.p0.x = line1.p1.x = 20;
	line1.p0.y = 0;
	line1.p1.y = 5;

	line2.p0.x = line2.p1.x = 25;
	line2.p0.y = 0;
	line2.p1.y = 5;

	line3.p0.x = line3.p1.x = 30;
	line3.p0.y = 0;
	line3.p1.y = 5;

	line4.p0.x = line4.p1.x = 35;
	line4.p0.y = 0;
	line4.p1.y = 5;

	pNewChip = new CChip(10, 30, 60, 5, "DK0509", &line1, &line2, &line3, &line4);

	pNewChip->m_sCount = -1;

	m_pChipsArr[m_uCountChip++] = pNewChip;

	UpdateGabRect(*pNewChip);

//== Vergrosserung

	long lDx = (long)((m_rectGabarit.right - m_rectGabarit.left)/20.);
	long lDy = (long)((m_rectGabarit.bottom - m_rectGabarit.top)/20.);

	m_rectGabarit.right += lDx;
	m_rectGabarit.left -= lDx;
	m_rectGabarit.top -= lDy;
	m_rectGabarit.bottom += lDy;

}

void CIntCircuitCtl::UpdateGabRect(const RECT& newRect)
{
	if(m_rectGabarit.top < newRect.top)
		m_rectGabarit.top = newRect.top;

	if(m_rectGabarit.right < newRect.right)
		m_rectGabarit.right = newRect.right;

}

void CIntCircuitCtl::FinalRelease()
{
	for(UINT i= 0; i < m_uCountChip; i++)
	{
		delete m_pChipsArr[i];
	}
}

STDMETHODIMP CIntCircuitCtl::get_IsStockOK(BOOL * pVal)
{
	// TODO: Add your implementation code here

	
	for(UINT i= 0; i < m_uCountChip; i++)
	{
		if(m_pChipsArr[i]->m_sCount < 0)
		{
			*pVal = FALSE;
			return S_OK;
		}

	}

	*pVal = TRUE;
	return S_OK;
}


STDMETHODIMP CIntCircuitCtl::Count(BSTR bstrName, short * sCount)
{
	// TODO: Add your implementation code here
	
	USES_CONVERSION;

	char* str = W2T(bstrName);

	for(UINT i= 0; i < m_uCountChip; i++)
	{
		if(::strcmp(m_pChipsArr[i]->m_strName, str) == 0)
		{
			*sCount = m_pChipsArr[i]->m_sCount;

			if(*sCount < -2)
				return Error(_T("Zu viel Chips fehlt!"));

			return S_OK;
		}
	}

	*sCount = -1000;

	return CTL_E_INVALIDPROPERTYVALUE;
}


LRESULT CIntCircuitCtl::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHanled)
{
	WORD xPos = LOWORD(lParam);
	WORD yPos = HIWORD(lParam);

	RECT rect;
	GetClientRect(&rect);

	for(UINT i= 0; i < m_uCountChip; i++)
	{
		bool bRes = m_pChipsArr[i]->HitTestDraw(xPos, yPos, rect, m_rectGabarit);
		if(bRes)
		{
			CChoiceDlg dlg;
			dlg.m_pChip = m_pChipsArr[i];

			short sOldCount = m_pChipsArr[i]->m_sCount;
			dlg.DoModal();

			if(sOldCount != m_pChipsArr[i]->m_sCount)
			{
				//== Gab es eine Bestellung 
				CComBSTR bstrName(m_pChipsArr[i]->m_strName);
				Fire_NewOrder(bstrName);
				Invalidate();
			}

		}

	}

	return 0;
}

STDMETHODIMP CIntCircuitCtl::get_CountByIndex(short sIndex, short * pVal)
{
	// TODO: Add your implementation code here

	if((sIndex < 0)||((UINT)sIndex > m_uCountChip))
	{
		return CTL_E_INVALIDPROPERTYVALUE;
	}
		
	*pVal = m_pChipsArr[sIndex]->m_sCount;

	return S_OK;
}

STDMETHODIMP CIntCircuitCtl::put_CountByIndex(short sIndex, short newVal)
{
	// TODO: Add your implementation code here

	if((sIndex < 0)||((UINT)sIndex > m_uCountChip))
	{
		return CTL_E_INVALIDPROPERTYVALUE;
	}
		
	m_pChipsArr[sIndex]->m_sCount = newVal;

	return S_OK;
}
