// TaskManagerCOMDoc.cpp : implementation of the CTaskManagerCOMDoc class
//

#include "stdafx.h"
#include "TaskManagerCOM.h"

#include "TaskManagerCOMDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMDoc

IMPLEMENT_DYNCREATE(CTaskManagerCOMDoc, CDocument)

BEGIN_MESSAGE_MAP(CTaskManagerCOMDoc, CDocument)
	//{{AFX_MSG_MAP(CTaskManagerCOMDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMDoc construction/destruction

CTaskManagerCOMDoc::CTaskManagerCOMDoc()
{
	// TODO: add one-time construction code here

}

CTaskManagerCOMDoc::~CTaskManagerCOMDoc()
{
}

BOOL CTaskManagerCOMDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMDoc serialization

void CTaskManagerCOMDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMDoc diagnostics

#ifdef _DEBUG
void CTaskManagerCOMDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTaskManagerCOMDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMDoc commands
