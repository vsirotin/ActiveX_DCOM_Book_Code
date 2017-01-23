// DCOMSpaceInfoDoc.h : interface of the CDCOMSpaceInfoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCOMSPACEINFODOC_H__EEB67431_087B_11D2_B890_808E7145DC12__INCLUDED_)
#define AFX_DCOMSPACEINFODOC_H__EEB67431_087B_11D2_B890_808E7145DC12__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CDCOMSpaceInfoDoc : public CDocument
{
protected: // create from serialization only
	CDCOMSpaceInfoDoc();
	DECLARE_DYNCREATE(CDCOMSpaceInfoDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDCOMSpaceInfoDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDCOMSpaceInfoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDCOMSpaceInfoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CDCOMSpaceInfoDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCOMSPACEINFODOC_H__EEB67431_087B_11D2_B890_808E7145DC12__INCLUDED_)
