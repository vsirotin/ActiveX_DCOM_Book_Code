// Chip.h: interface for the CChip class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHIP_H__8A8F3724_EFBF_11D1_A2BA_00A0C941DD59__INCLUDED_)
#define AFX_CHIP_H__8A8F3724_EFBF_11D1_A2BA_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

typedef struct tagLINE
{
	POINT p0;
	POINT p1;
} LINE;



class CChip : public RECT  
{
public:
	CChip();
	CChip(short x0, short y0, short x1, short y1, char* strName = NULL, 
		LINE* pLine1 = NULL, LINE* pLine2 = NULL, LINE* pLine3 = NULL, LINE* pLine4 = NULL);

	virtual ~CChip();

//== Attributes:
public:
	char m_strName[10];
	short m_sCount; //== m_sCount < 0 : ist bestellt

protected:

	LINE m_contact[4];
	UINT m_uCountContact;

public:
//= Operations:
	bool Draw(ATL_DRAWINFO& di, const RECT& rectCircuit);
	bool HitTestDraw(WORD xPos, WORD yPos, const RECT& rectClientWnd, const RECT& rectCircuit);

};

#endif // !defined(AFX_CHIP_H__8A8F3724_EFBF_11D1_A2BA_00A0C941DD59__INCLUDED_)
