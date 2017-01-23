// TaskManagerCOMView.h : interface of the CTaskManagerCOMView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKMANAGERCOMVIEW_H__88A3FA11_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGERCOMVIEW_H__88A3FA11_A12F_11D1_A259_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000



struct IJobAlloc;
struct IJobInfo;

class CTaskManagerCOMView : public CEditView
{
protected: // create from serialization only
	CTaskManagerCOMView();
	DECLARE_DYNCREATE(CTaskManagerCOMView)

// Attributes
public:
	CTaskManagerCOMDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerCOMView)
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

private:
	void SetJobAllocObj();
	void SetUseName();

	IJobAlloc* m_pIJobAlloc;
	IJobInfo* m_pIJobInfo;
	int m_nCurrJob;

//	OLECHAR FAR* m_polecharUserName;
	BSTR m_bstrUserName;
	
	CString m_strProtocol;

	virtual ~CTaskManagerCOMView();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskManagerCOMView)
	afx_msg void OnJobNew();
	afx_msg void OnJobPause();
	afx_msg void OnJobOk();
	afx_msg void OnJobGetInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()


	

};

#ifndef _DEBUG  // debug version in TaskManagerCOMView.cpp
inline CTaskManagerCOMDoc* CTaskManagerCOMView::GetDocument()
   { return (CTaskManagerCOMDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGERCOMVIEW_H__88A3FA11_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
