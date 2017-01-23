// AdrListViewView.h : interface of the CAdrListViewView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADRLISTVIEWVIEW_H__35A69B6F_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
#define AFX_ADRLISTVIEWVIEW_H__35A69B6F_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAdrListViewView : public CEditView
{
protected: // create from serialization only
	CAdrListViewView();
	DECLARE_DYNCREATE(CAdrListViewView)

// Attributes
public:
	CAdrListViewDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListViewView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAdrListViewView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAdrListViewView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AdrListViewView.cpp
inline CAdrListViewDoc* CAdrListViewView::GetDocument()
   { return (CAdrListViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLISTVIEWVIEW_H__35A69B6F_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
