#if !defined(AFX_AXDMFCCONTROLFIRSTPPG_H__BD7B060D_D5DD_11D1_B890_B52A27C48724__INCLUDED_)
#define AFX_AXDMFCCONTROLFIRSTPPG_H__BD7B060D_D5DD_11D1_B890_B52A27C48724__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// AxDMFCControlFirstPpg.h : Declaration of the CAxDMFCControlFirstPropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CAxDMFCControlFirstPropPage : See AxDMFCControlFirstPpg.cpp.cpp for implementation.

class CAxDMFCControlFirstPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CAxDMFCControlFirstPropPage)
	DECLARE_OLECREATE_EX(CAxDMFCControlFirstPropPage)

// Constructor
public:
	CAxDMFCControlFirstPropPage();

// Dialog Data
	//{{AFX_DATA(CAxDMFCControlFirstPropPage)
	enum { IDD = IDD_PROPPAGE_AXDMFCCONTROLFIRST };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CAxDMFCControlFirstPropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AXDMFCCONTROLFIRSTPPG_H__BD7B060D_D5DD_11D1_B890_B52A27C48724__INCLUDED)
