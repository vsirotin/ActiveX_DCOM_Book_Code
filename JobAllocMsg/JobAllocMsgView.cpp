// JobAllocMsgView.cpp : implementation of the CJobAllocMsgView class
//

#include "stdafx.h"
#include "JobAllocMsg.h"

#include "JobAllocMsgDoc.h"
#include "JobAllocMsgView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView

IMPLEMENT_DYNCREATE(CJobAllocMsgView, CEditView)

BEGIN_MESSAGE_MAP(CJobAllocMsgView, CEditView)
	//{{AFX_MSG_MAP(CJobAllocMsgView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView construction/destruction

CJobAllocMsgView::CJobAllocMsgView()
{
	// TODO: add construction code here
	theApp.m_pView = this;
}

CJobAllocMsgView::~CJobAllocMsgView()
{
}

BOOL CJobAllocMsgView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView drawing

void CJobAllocMsgView::OnDraw(CDC* pDC)
{
	CJobAllocMsgDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView printing

BOOL CJobAllocMsgView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CJobAllocMsgView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CJobAllocMsgView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView diagnostics

#ifdef _DEBUG
void CJobAllocMsgView::AssertValid() const
{
	CEditView::AssertValid();
}

void CJobAllocMsgView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CJobAllocMsgDoc* CJobAllocMsgView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CJobAllocMsgDoc)));
	return (CJobAllocMsgDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CJobAllocMsgView message handlers
/*

LRESULT CJobAllocMsgView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CEditView::DefWindowProc(message, wParam, lParam);
}

*/
LRESULT CJobAllocMsgView::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	int i = 1;
	COPYDATASTRUCT* pCds;
	switch(message)
	{
		case WM_USER + 1: //== Erledigt
			i = 2;
			break;

		case WM_COPYDATA: //== Anhalten
			{
			

			pCds = (COPYDATASTRUCT*)lParam;

			DWORD dwData = pCds->dwData;
			
			char* pcText = (char*)pCds->lpData;

			CString strTmp(pcText);
	/*
			cds.dwData = 12;
			
			CString strTmp("Test Txt");

			const char* pc = LPCTSTR(strTmp);

			cds.cbData = sizeof(strTmp);

			cds.lpData = (PVOID)pc;

	*/
			i = 3;
			}

			return (LRESULT)TRUE;
		
		case WM_USER + 2: //== Neue Aufgabe
			i = 3;
			break;
		default:
			break;
	}
	return CEditView::DefWindowProc(message, wParam, lParam);
}