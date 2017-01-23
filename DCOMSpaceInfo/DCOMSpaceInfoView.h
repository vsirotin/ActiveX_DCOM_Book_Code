// DCOMSpaceInfoView.h : interface of the CDCOMSpaceInfoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCOMSPACEINFOVIEW_H__EEB67433_087B_11D2_B890_808E7145DC12__INCLUDED_)
#define AFX_DCOMSPACEINFOVIEW_H__EEB67433_087B_11D2_B890_808E7145DC12__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "connectorproxy.h"
class CDCOMSpaceInfoView : public CView
{
protected: // create from serialization only
	CDCOMSpaceInfoView();
	DECLARE_DYNCREATE(CDCOMSpaceInfoView)

// Attributes
public:
	CDCOMSpaceInfoDoc* GetDocument();

	CObList m_oblistValues;
	CString m_strComputerName;
	IConnector m_server;
	CString m_strObjExist;
	long m_lSpacePhysTotal;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCOMSpaceInfoView)
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
	virtual ~CDCOMSpaceInfoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDCOMSpaceInfoView)
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DCOMSpaceInfoView.cpp
inline CDCOMSpaceInfoDoc* CDCOMSpaceInfoView::GetDocument()
   { return (CDCOMSpaceInfoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCOMSPACEINFOVIEW_H__EEB67433_087B_11D2_B890_808E7145DC12__INCLUDED_)
