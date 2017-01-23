// RoomWWWDoc.h : interface of the CRoomWWWDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROOMWWWDOC_H__1FA04A0B_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
#define AFX_ROOMWWWDOC_H__1FA04A0B_FA6E_11D1_B890_C384C30BFC13__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CRoomWWWDoc : public CDocument
{
protected: // create from serialization only
	CRoomWWWDoc();
	DECLARE_DYNCREATE(CRoomWWWDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRoomWWWDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRoomWWWDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRoomWWWDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ROOMWWWDOC_H__1FA04A0B_FA6E_11D1_B890_C384C30BFC13__INCLUDED_)
