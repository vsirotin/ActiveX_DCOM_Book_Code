// AdrListDoc.cpp : implementation of the CAdrListDoc class
//

#include "stdafx.h"
#include "AdrList.h"

#include "AdrListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdrListDoc

IMPLEMENT_DYNCREATE(CAdrListDoc, CDocument)

BEGIN_MESSAGE_MAP(CAdrListDoc, CDocument)
	//{{AFX_MSG_MAP(CAdrListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAdrListDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CAdrListDoc)
	DISP_PROPERTY_NOTIFY(CAdrListDoc, "Name", m_name, OnNameChanged, VT_BSTR)
	DISP_PROPERTY_NOTIFY(CAdrListDoc, "PLZ", m_pLZ, OnPLZChanged, VT_BSTR)
	DISP_PROPERTY_EX(CAdrListDoc, "Strasse", GetStrasse, SetStrasse, VT_BSTR)
	DISP_FUNCTION(CAdrListDoc, "Next", Next, VT_BOOL, VTS_NONE)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IAdrList to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {2D81BA45-C815-11D1-B890-EF240A666978}
static const IID IID_IAdrList =
{ 0x2d81ba45, 0xc815, 0x11d1, { 0xb8, 0x90, 0xef, 0x24, 0xa, 0x66, 0x69, 0x78 } };

BEGIN_INTERFACE_MAP(CAdrListDoc, CDocument)
	INTERFACE_PART(CAdrListDoc, IID_IAdrList, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdrListDoc construction/destruction

CAdrListDoc::CAdrListDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
	m_iNumbAdr = 0;

	m_name = CString("Schmidt");
	m_pLZ = CString("45721 Haltern");
}

CAdrListDoc::~CAdrListDoc()
{
	AfxOleUnlockApp();
}

BOOL CAdrListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAdrListDoc serialization

void CAdrListDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListDoc diagnostics

#ifdef _DEBUG
void CAdrListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAdrListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdrListDoc commands

BOOL CAdrListDoc::Next() 
{
	// TODO: Add your dispatch handler code here

	m_iNumbAdr++;
	if(m_iNumbAdr > 1)
		return FALSE;

	
	m_name = CString("Müller");
	m_pLZ = CString("58099 Hagen");

	return TRUE;
}

void CAdrListDoc::OnNameChanged() 
{
	// TODO: Add notification handler code

}

BSTR CAdrListDoc::GetStrasse() 
{
	CString strResult("Lessingstr. 274");
	if(m_iNumbAdr > 0)
		strResult = CString("Sixtus Str. 216");

	return strResult.AllocSysString();
}

void CAdrListDoc::SetStrasse(LPCTSTR lpszNewValue) 
{
	// TODO: Add your property handler here

}

void CAdrListDoc::OnPLZChanged() 
{
	// TODO: Add notification handler code

}
