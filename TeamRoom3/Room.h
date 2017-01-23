// Room.h: interface for the CRoom class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOM_H__89244263_DD1D_11D1_B890_8C54C4583121__INCLUDED_)
#define AFX_ROOM_H__89244263_DD1D_11D1_B890_8C54C4583121__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CRoom 
{
public:
	CRoom();
	CRoom(const CPoint& p0, const CPoint& p1, const CPoint& pointDoor);
	
	virtual ~CRoom();

	void SetColor(const COLORREF& color);
	COLORREF GetColor();
	void Draw(CDC* pdc, const CRect& rcBound, const CSize& sizeInMetr);
	bool HitTest(const CRect& rectClient, const CSize& m_sizeInMetr, const CPoint& point);
	void CRoom::DoPropExchange(CPropExchange* pPX, int i);
	CString MakeUName(int i, LPCSTR strName);
	
public:

	short m_iCount;
	float m_fSum;
	CString m_strName;
	CString m_strInfo;

private:
	
	CPoint m_p0;
	CPoint m_p1;
	CPoint m_pDoor;

	COLORREF m_color;

};

#endif // !defined(AFX_ROOM_H__89244263_DD1D_11D1_B890_8C54C4583121__INCLUDED_)
