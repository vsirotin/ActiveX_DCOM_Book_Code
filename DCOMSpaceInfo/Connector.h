#if !defined(AFX_CONNECTOR_H__EEB6743E_087B_11D2_B890_808E7145DC12__INCLUDED_)
#define AFX_CONNECTOR_H__EEB6743E_087B_11D2_B890_808E7145DC12__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Connector.h : header file
//
#include <afxmt.h>


/////////////////////////////////////////////////////////////////////////////
// CConnector command target

class CConnector : public CCmdTarget
{
	DECLARE_DYNCREATE(CConnector)

	CConnector();           // protected constructor used by dynamic creation

// Attributes
public:

protected:

	static CCriticalSection m_critSect;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CConnector)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CConnector();

	// Generated message map functions
	//{{AFX_MSG(CConnector)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
	DECLARE_OLECREATE(CConnector)

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CConnector)
	afx_msg long GetPhysSpaceTotal();
	afx_msg float GetPhysSpaceAvail();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CONNECTOR_H__EEB6743E_087B_11D2_B890_808E7145DC12__INCLUDED_)
