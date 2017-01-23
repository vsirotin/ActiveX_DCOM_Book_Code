// AcDocView.h : interface of the CAcDocView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACDOCVIEW_H__4713B54D_062B_11D2_B890_C54647D3D618__INCLUDED_)
#define AFX_ACDOCVIEW_H__4713B54D_062B_11D2_B890_C54647D3D618__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CAcDocCntrItem;

class CAcDocView : public CFormView
{
protected: // create from serialization only
	CAcDocView();
	DECLARE_DYNCREATE(CAcDocView)

public:
	//{{AFX_DATA(CAcDocView)
	enum { IDD = IDD_ACDOC_FORM };
	CListBox	m_listbox;
	UINT	m_uCount;
	CString	m_strGUID;
	UINT	m_uPrice;
	CString	m_strTyp;
	//}}AFX_DATA

// Attributes
public:
	CAcDocDoc* GetDocument();
	// m_pSelection holds the selection to the current CAcDocCntrItem.
	// For many applications, such a member variable isn't adequate to
	//  represent a selection, such as a multiple selection or a selection
	//  of objects that are not CAcDocCntrItem objects.  This selection
	//  mechanism is provided just to help you get started.

	// TODO: replace this selection mechanism with one appropriate to your app.
	CAcDocCntrItem* m_pSelection;

// Operations
public:

	void InitElem(); 

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcDocView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo*);
	virtual BOOL IsSelected(const CObject* pDocItem) const;// Container support
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAcDocView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAcDocView)
	afx_msg void OnDestroy();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnInsertObject();
	afx_msg void OnCancelEditCntr();
	afx_msg void OnCancelEditSrvr();
	afx_msg void OnElemToList();
	afx_msg void OnSelchangeList1();
	afx_msg void OnNewElem();
	afx_msg void OnUpdateTyp();
	afx_msg void OnEditCopy();
	afx_msg void OnEditCut();
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in AcDocView.cpp
inline CAcDocDoc* CAcDocView::GetDocument()
   { return (CAcDocDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACDOCVIEW_H__4713B54D_062B_11D2_B890_C54647D3D618__INCLUDED_)
