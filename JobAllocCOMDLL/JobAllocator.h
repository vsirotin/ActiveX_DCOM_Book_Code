#if !defined(AFX_JOBALLOCATOR_H__88A3FA04_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
#define AFX_JOBALLOCATOR_H__88A3FA04_A12F_11D1_A259_00A0C941DD59__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// JobAllocator.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CJobAllocator command target


class CJobAllocator : public CCmdTarget
{
	DECLARE_DYNCREATE(CJobAllocator)

	CJobAllocator();           // protected constructor used by dynamic creation

// Attributes
public:
 
// Operations
public:

private:

	int m_iCurrJob;
	BSTR m_bstrInfo;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CJobAllocator)
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CJobAllocator();

	// Generated message map functions
	//{{AFX_MSG(CJobAllocator)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	DECLARE_OLECREATE(CJobAllocator)

	BEGIN_INTERFACE_PART(JobAlloc, IJobAlloc)
		STDMETHOD_(int&, Pause)(int nJob, BSTR bstrReason);
		STDMETHOD_(int&, NewJob)(BSTR bstrUserName);
		STDMETHOD (JobOk)(int nJob);
	END_INTERFACE_PART(JobAlloc);

	BEGIN_INTERFACE_PART(JobInfo, IJobInfo)
		STDMETHOD_(BSTR&, GetInfo)(int nJob);
	END_INTERFACE_PART(JobInfo);

	DECLARE_INTERFACE_MAP();

};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_JOBALLOCATOR_H__88A3FA04_A12F_11D1_A259_00A0C941DD59__INCLUDED_)
