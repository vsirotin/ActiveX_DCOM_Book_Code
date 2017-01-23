// AdrListDoc.h : interface of the CAdrListDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADRLISTDOC_H__2D81BA4F_C815_11D1_B890_EF240A666978__INCLUDED_)
#define AFX_ADRLISTDOC_H__2D81BA4F_C815_11D1_B890_EF240A666978__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CAdrListDoc : public CDocument
{
protected: // create from serialization only
	CAdrListDoc();
	DECLARE_DYNCREATE(CAdrListDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdrListDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAdrListDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAdrListDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CAdrListDoc)
	CString m_name;
	afx_msg void OnNameChanged();
	CString m_pLZ;
	afx_msg void OnPLZChanged();
	afx_msg BSTR GetStrasse();
	afx_msg void SetStrasse(LPCTSTR lpszNewValue);
	afx_msg BOOL Next();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
private:
	int m_iNumbAdr;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADRLISTDOC_H__2D81BA4F_C815_11D1_B890_EF240A666978__INCLUDED_)
