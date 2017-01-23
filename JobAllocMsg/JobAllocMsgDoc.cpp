// JobAllocMsgDoc.cpp : implementation of the CJobAllocMsgDoc class
//

#include "stdafx.h"
#include "JobAllocMsg.h"

#include "JobAllocMsgDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgDoc

IMPLEMENT_DYNCREATE(CJobAllocMsgDoc, CDocument)

BEGIN_MESSAGE_MAP(CJobAllocMsgDoc, CDocument)
	//{{AFX_MSG_MAP(CJobAllocMsgDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgDoc construction/destruction

CJobAllocMsgDoc::CJobAllocMsgDoc()
{
	// TODO: add one-time construction code here

}

CJobAllocMsgDoc::~CJobAllocMsgDoc()
{
}

BOOL CJobAllocMsgDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgDoc serialization

void CJobAllocMsgDoc::Serialize(CArchive& ar)
{
	// CEditView contains an edit control which handles all serialization
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgDoc diagnostics

#ifdef _DEBUG
void CJobAllocMsgDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CJobAllocMsgDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgDoc commands
