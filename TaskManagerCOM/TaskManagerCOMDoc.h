// TaskManagerCOMDoc.h : interface of the CTaskManagerCOMDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TASKMANAGERCOMDOC_H__88A3FA0F_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
#define AFX_TASKMANAGERCOMDOC_H__88A3FA0F_A12F_11D1_A259_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000


class CTaskManagerCOMDoc : public CDocument
{
protected: // create from serialization only
	CTaskManagerCOMDoc();
	DECLARE_DYNCREATE(CTaskManagerCOMDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTaskManagerCOMDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTaskManagerCOMDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTaskManagerCOMDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TASKMANAGERCOMDOC_H__88A3FA0F_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
