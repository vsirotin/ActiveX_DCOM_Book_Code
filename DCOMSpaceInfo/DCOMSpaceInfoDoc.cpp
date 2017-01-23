// DCOMSpaceInfoDoc.cpp : implementation of the CDCOMSpaceInfoDoc class
//

#include "stdafx.h"
#include "DCOMSpaceInfo.h"

#include "DCOMSpaceInfoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoDoc

IMPLEMENT_DYNCREATE(CDCOMSpaceInfoDoc, CDocument)

BEGIN_MESSAGE_MAP(CDCOMSpaceInfoDoc, CDocument)
	//{{AFX_MSG_MAP(CDCOMSpaceInfoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CDCOMSpaceInfoDoc, CDocument)
	//{{AFX_DISPATCH_MAP(CDCOMSpaceInfoDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IDCOMSpaceInfo to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {EEB67425-087B-11D2-B890-808E7145DC12}
static const IID IID_IDCOMSpaceInfo =
{ 0xeeb67425, 0x87b, 0x11d2, { 0xb8, 0x90, 0x80, 0x8e, 0x71, 0x45, 0xdc, 0x12 } };

BEGIN_INTERFACE_MAP(CDCOMSpaceInfoDoc, CDocument)
	INTERFACE_PART(CDCOMSpaceInfoDoc, IID_IDCOMSpaceInfo, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoDoc construction/destruction

CDCOMSpaceInfoDoc::CDCOMSpaceInfoDoc()
{
	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CDCOMSpaceInfoDoc::~CDCOMSpaceInfoDoc()
{
	AfxOleUnlockApp();
}

BOOL CDCOMSpaceInfoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoDoc serialization

void CDCOMSpaceInfoDoc::Serialize(CArchive& ar)
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
// CDCOMSpaceInfoDoc diagnostics

#ifdef _DEBUG
void CDCOMSpaceInfoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDCOMSpaceInfoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDCOMSpaceInfoDoc commands
