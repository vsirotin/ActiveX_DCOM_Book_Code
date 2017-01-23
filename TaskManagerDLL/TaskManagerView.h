// TaskManagerView.h : interface of the CTaskManagerView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKMANAGERVIEW_H__401F3094_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGERVIEW_H__401F3094_93C7_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "c:\VCPP\AxD\kap2\JobAllocDLL\JobAllocManager.h"
class CTaskManagerView : public CEditView
{
protected: // create from serialization only
	CTaskManagerView();
	DECLARE_DYNCREATE(CTaskManagerView)

// Attributes
public:
	CTaskManagerDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerView)
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

	CJobAllocManager m_joballocman;
	CString m_strProtocol;
	UINT m_nCurrJob;
	virtual ~CTaskManagerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskManagerView)
	afx_msg void OnJobNew();
	afx_msg void OnJobOk();
	afx_msg void OnJobPause();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	HWND FindJobAllocWnd();
};

#ifndef _DEBUG  // debug version in TaskManagerView.cpp
inline CTaskManagerDoc* CTaskManagerView::GetDocument()
   { return (CTaskManagerDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGERVIEW_H__401F3094_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
