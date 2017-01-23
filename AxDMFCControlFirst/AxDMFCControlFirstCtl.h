#if !defined(AFX_AXDMFCCONTROLFIRSTCTL_H__BD7B060B_D5DD_11D1_B890_B52A27C48724__INCLUDED_)
#define AFX_AXDMFCCONTROLFIRSTCTL_H__BD7B060B_D5DD_11D1_B890_B52A27C48724__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// AxDMFCControlFirstCtl.h : Declaration of the CAxDMFCControlFirstCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstCtrl : See AxDMFCControlFirstCtl.cpp for implementation.

class CAxDMFCControlFirstCtrl : public COleControl
{
	DECLARE_DYNCREATE(CAxDMFCControlFirstCtrl)

// Constructor
public:
	CAxDMFCControlFirstCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAxDMFCControlFirstCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CAxDMFCControlFirstCtrl();

	DECLARE_OLECREATE_EX(CAxDMFCControlFirstCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CAxDMFCControlFirstCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CAxDMFCControlFirstCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CAxDMFCControlFirstCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CAxDMFCControlFirstCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CAxDMFCControlFirstCtrl)
	afx_msg short GetXRes();
	afx_msg void SetXRes(short nNewValue);
	afx_msg short GetYRes();
	afx_msg void SetYRes(short nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CAxDMFCControlFirstCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

//Attributes:
	short m_xRes;
	short m_yRes;

// Dispatch and event IDs
public:

	enum {
	//{{AFX_DISP_ID(CAxDMFCControlFirstCtrl)
	dispidXRes = 1L,
	dispidYRes = 2L,
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXDMFCCONTROLFIRSTCTL_H__BD7B060B_D5DD_11D1_B890_B52A27C48724__INCLUDED)
