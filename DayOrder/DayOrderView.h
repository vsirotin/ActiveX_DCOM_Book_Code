// DayOrderView.h : interface of the CDayOrderView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "calendar.h"
#include "intcircuitctl.h"
//}}AFX_INCLUDES

#if !defined(AFX_DAYORDERVIEW_H__9A13BCED_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
#define AFX_DAYORDERVIEW_H__9A13BCED_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

struct DAY_ORDER;
class CDayOrderView : public CFormView
{
protected: // create from serialization only
	CDayOrderView();
	DECLARE_DYNCREATE(CDayOrderView)

public:
	//{{AFX_DATA(CDayOrderView)
	enum { IDD = IDD_DAYORDER_FORM };
	CCalendar	m_calendar;
	CIntCircuitCtl	m_circuit;
	//}}AFX_DATA

// Attributes
public:
	CDayOrderDoc* GetDocument();

private:
	DAY_ORDER* m_pDAY_ORDER;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDayOrderView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDayOrderView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDayOrderView)
	afx_msg void OnNewOrderIntcircuitctl1(LPCTSTR bstrName);
	afx_msg void OnClickCalendar1();
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DayOrderView.cpp
inline CDayOrderDoc* CDayOrderView::GetDocument()
   { return (CDayOrderDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAYORDERVIEW_H__9A13BCED_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
