// RoomWWWDoc.cpp : implementation of the CRoomWWWDoc class
//

#include "stdafx.h"
#include "RoomWWW.h"

#include "RoomWWWDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWDoc

IMPLEMENT_DYNCREATE(CRoomWWWDoc, CDocument)

BEGIN_MESSAGE_MAP(CRoomWWWDoc, CDocument)
	//{{AFX_MSG_MAP(CRoomWWWDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWDoc construction/destruction

CRoomWWWDoc::CRoomWWWDoc()
{
	// TODO: add one-time construction code here

}

CRoomWWWDoc::~CRoomWWWDoc()
{
}

BOOL CRoomWWWDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRoomWWWDoc serialization

void CRoomWWWDoc::Serialize(CArchive& ar)
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
// CRoomWWWDoc diagnostics

#ifdef _DEBUG
void CRoomWWWDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRoomWWWDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRoomWWWDoc commands
