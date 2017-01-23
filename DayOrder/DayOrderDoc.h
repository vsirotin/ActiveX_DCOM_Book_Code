// DayOrderDoc.h : interface of the CDayOrderDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DAYORDERDOC_H__9A13BCEB_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
#define AFX_DAYORDERDOC_H__9A13BCEB_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


struct DAY_ORDER{
	short sJahr;
	short sMonat;
	short sTag;
	short sVals[3];
};

class CDayOrderDoc : public CDocument
{
protected: // create from serialization only
	CDayOrderDoc();
	DECLARE_DYNCREATE(CDayOrderDoc)

// Attributes
public:
	CObList m_oblistDayOrder;  

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDayOrderDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDayOrderDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDayOrderDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DAYORDERDOC_H__9A13BCEB_FE3D_11D1_B890_DBDAD6F5BD11__INCLUDED_)
