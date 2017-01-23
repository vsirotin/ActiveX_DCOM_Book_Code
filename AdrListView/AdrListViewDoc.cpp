// AdrListViewDoc.cpp : implementation of the CAdrListViewDoc class
//

#include "stdafx.h"
#include "AdrListView.h"

#include "AdrListViewDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewDoc

IMPLEMENT_DYNCREATE(CAdrListViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CAdrListViewDoc, CDocument)
	//{{AFX_MSG_MAP(CAdrListViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewDoc construction/destruction

CAdrListViewDoc::CAdrListViewDoc()
{
	// TODO: add one-time construction code here

}

CAdrListViewDoc::~CAdrListViewDoc()
{
}

BOOL CAdrListViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CAdrListViewDoc serialization

void CAdrListViewDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewDoc diagnostics

#ifdef _DEBUG
void CAdrListViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CAdrListViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewDoc commands
