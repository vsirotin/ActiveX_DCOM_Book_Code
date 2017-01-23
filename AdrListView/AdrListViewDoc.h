// AdrListViewDoc.h : interface of the CAdrListViewDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADRLISTVIEWDOC_H__35A69B6D_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
#define AFX_ADRLISTVIEWDOC_H__35A69B6D_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CAdrListViewDoc : public CDocument
{
protected: // create from serialization only
	CAdrListViewDoc();
	DECLARE_DYNCREATE(CAdrListViewDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListViewDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAdrListViewDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAdrListViewDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLISTVIEWDOC_H__35A69B6D_D3A9_11D1_B890_B9B3233DAD26__INCLUDED_)
