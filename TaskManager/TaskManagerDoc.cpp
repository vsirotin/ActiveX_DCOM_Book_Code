// TaskManagerDoc.cpp : implementation of the CTaskManagerDoc class
//

#include "stdafx.h"
#include "TaskManager.h"

#include "TaskManagerDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerDoc

IMPLEMENT_DYNCREATE(CTaskManagerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTaskManagerDoc, CDocument)
	//{{AFX_MSG_MAP(CTaskManagerDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerDoc construction/destruction

CTaskManagerDoc::CTaskManagerDoc()
{
	// TODO: add one-time construction code here

}

CTaskManagerDoc::~CTaskManagerDoc()
{
}

BOOL CTaskManagerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTaskManagerDoc serialization

void CTaskManagerDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerDoc diagnostics

#ifdef _DEBUG
void CTaskManagerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTaskManagerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerDoc commands
