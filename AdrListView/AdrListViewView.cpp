// AdrListViewView.cpp : implementation of the CAdrListViewView class
//

#include "stdafx.h"
#include "AdrListView.h"

#include "AdrListViewDoc.h"
#include "AdrListViewView.h"
#include "adrlist.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView

IMPLEMENT_DYNCREATE(CAdrListViewView, CEditView)

BEGIN_MESSAGE_MAP(CAdrListViewView, CEditView)
	//{{AFX_MSG_MAP(CAdrListViewView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView construction/destruction

CAdrListViewView::CAdrListViewView()
{
	// TODO: add construction code here

}

CAdrListViewView::~CAdrListViewView()
{
}

BOOL CAdrListViewView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView drawing

void CAdrListViewView::OnDraw(CDC* pDC)
{
	CAdrListViewDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView printing

BOOL CAdrListViewView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CAdrListViewView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CAdrListViewView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView diagnostics

#ifdef _DEBUG
void CAdrListViewView::AssertValid() const
{
	CEditView::AssertValid();
}

void CAdrListViewView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CAdrListViewDoc* CAdrListViewView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdrListViewDoc)));
	return (CAdrListViewDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdrListViewView message handlers

void CAdrListViewView::OnInitialUpdate() 
{
	CEditView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class


	IAdrList proxyAdrList;

	BOOL bRes = proxyAdrList.CreateDispatch("AdrList.Document");

	if(!bRes)
	{
		TRACE("Automatisierungsobjekt nicht gefunden!!\n");
		return;
	}
	
	CString strTmp;

	CString strName, strStrasse, strPLZ;
	CString strTab("\t");
	CString strRet("\r\n");
	while(bRes)
	{
		strName = proxyAdrList.GetName();
		strStrasse = proxyAdrList.GetStrasse();
		strPLZ = proxyAdrList.GetPlz();

		strTmp += strName + strTab + strStrasse + strTab + strPLZ + strRet;
		
		bRes = proxyAdrList.Next();
	}

	SetWindowText(strTmp);
}
