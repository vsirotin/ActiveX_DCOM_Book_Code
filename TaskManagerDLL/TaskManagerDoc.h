// TaskManagerDoc.h : interface of the CTaskManagerDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKMANAGERDOC_H__401F3092_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGERDOC_H__401F3092_93C7_11D1_A24A_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTaskManagerDoc : public CDocument
{
protected: // create from serialization only
	CTaskManagerDoc();
	DECLARE_DYNCREATE(CTaskManagerDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTaskManagerDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskManagerDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGERDOC_H__401F3092_93C7_11D1_A24A_00A0C941DD59__INCLUDED_)
