// AdrListView.h : interface of the CAdrListView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADRLISTVIEW_H__2D81BA51_C815_11D1_B890_EF240A666978__INCLUDED_)
#define AFX_ADRLISTVIEW_H__2D81BA51_C815_11D1_B890_EF240A666978__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAdrListView : public CView
{
protected: // create from serialization only
	CAdrListView();
	DECLARE_DYNCREATE(CAdrListView)

// Attributes
public:
	CAdrListDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListView)
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
	virtual ~CAdrListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAdrListView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AdrListView.cpp
inline CAdrListDoc* CAdrListView::GetDocument()
   { return (CAdrListDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLISTVIEW_H__2D81BA51_C815_11D1_B890_EF240A666978__INCLUDED_)
