// RoomWWWView.h : interface of the CRoomWWWView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOMWWWVIEW_H__1FA04A0D_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
#define AFX_ROOMWWWVIEW_H__1FA04A0D_FA6E_11D1_B890_C384C30BFC13__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "TeamRoom.h"
#include "WebBrowser2.h" 

class CRoomWWWView : public CView
{
protected: // create from serialization only
	CRoomWWWView();
	DECLARE_DYNCREATE(CRoomWWWView)

// Attributes
public:
	CRoomWWWDoc* GetDocument();

	CTeamRoom m_teamroom;
	CWebBrowser2 m_webbrowser;


// Operations
public:

	

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomWWWView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRoomWWWView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	
	afx_msg void OnFireClickInRoom(LPCTSTR strText);
	DECLARE_EVENTSINK_MAP();

// Generated message map functions
protected:
	//{{AFX_MSG(CRoomWWWView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RoomWWWView.cpp
inline CRoomWWWDoc* CRoomWWWView::GetDocument()
   { return (CRoomWWWDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMWWWVIEW_H__1FA04A0D_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
