// JobAllocMsgView.h : interface of the CJobAllocMsgView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_JOBALLOCMSGVIEW_H__401F30A8_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOCMSGVIEW_H__401F30A8_93C7_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CJobAllocMsgDoc; 
class CJobAllocMsgView : public CEditView
{
protected: // create from serialization only
	CJobAllocMsgView();
	DECLARE_DYNCREATE(CJobAllocMsgView)

// Attributes
public:
	CJobAllocMsgDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocMsgView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CJobAllocMsgView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CJobAllocMsgView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in JobAllocMsgView.cpp
inline CJobAllocMsgDoc* CJobAllocMsgView::GetDocument()
   { return (CJobAllocMsgDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOCMSGVIEW_H__401F30A8_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
