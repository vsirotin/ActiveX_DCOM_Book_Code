// AdrListView.cpp : implementation of the CAdrListView class
//

#include "stdafx.h"
#include "AdrList.h"

#include "AdrListDoc.h"
#include "AdrListView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdrListView

IMPLEMENT_DYNCREATE(CAdrListView, CView)

BEGIN_MESSAGE_MAP(CAdrListView, CView)
	//{{AFX_MSG_MAP(CAdrListView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdrListView construction/destruction

CAdrListView::CAdrListView()
{
	// TODO: add construction code here

}

CAdrListView::~CAdrListView()
{
}

BOOL CAdrListView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListView drawing

void CAdrListView::OnDraw(CDC* pDC)
{
	CAdrListDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListView printing

BOOL CAdrListView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CAdrListView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CAdrListView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CAdrListView diagnostics

#ifdef _DEBUG
void CAdrListView::AssertValid() const
{
	CView::AssertValid();
}

void CAdrListView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CAdrListDoc* CAdrListView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CAdrListDoc)));
	return (CAdrListDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAdrListView message handlers
