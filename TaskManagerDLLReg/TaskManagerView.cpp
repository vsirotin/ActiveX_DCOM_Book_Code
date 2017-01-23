// TaskManagerView.cpp : implementation of the CTaskManagerView class
//

#include "stdafx.h"
#include "TaskManager.h"

#include "TaskManagerDoc.h"
#include "TaskManagerView.h"
#include "ReasonDlg.h"
#include <string.h>



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView

IMPLEMENT_DYNCREATE(CTaskManagerView, CEditView)

BEGIN_MESSAGE_MAP(CTaskManagerView, CEditView)
	//{{AFX_MSG_MAP(CTaskManagerView)
	ON_COMMAND(ID_JOB_NEW, OnJobNew)
	ON_COMMAND(ID_JOB_OK, OnJobOk)
	ON_COMMAND(ID_JOB_PAUSE, OnJobPause)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView construction/destruction

CTaskManagerView::CTaskManagerView()
{
	// TODO: add construction code here
	m_nCurrJob = 0;
}

CTaskManagerView::~CTaskManagerView()
{
}

BOOL CTaskManagerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView drawing

void CTaskManagerView::OnDraw(CDC* pDC)
{
	CTaskManagerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView printing

BOOL CTaskManagerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CTaskManagerView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CTaskManagerView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView diagnostics

#ifdef _DEBUG
void CTaskManagerView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTaskManagerView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CTaskManagerDoc* CTaskManagerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTaskManagerDoc)));
	return (CTaskManagerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerView message handlers
#define MAX_SIZE_USER_NAME 100 
void CTaskManagerView::OnJobNew() 
{
	// TODO: Add your command handler code here

	char  cUserName[MAX_SIZE_USER_NAME];
	DWORD dwNameLen = MAX_SIZE_USER_NAME;

	::GetUserName(cUserName, &dwNameLen);
	CString strTmp(cUserName);

	LRESULT lRes = ::NewJob(strTmp);
		
	if(lRes > 0)
	{
		m_nCurrJob = (UINT)lRes;
		CTime t = CTime::GetCurrentTime();
		CString strTime = t.Format("%A %B %d %Y %H %M %S");
		CString strTmp;
		strTmp.Format(" Neue Job N %d\r\n", m_nCurrJob); 
		m_strProtocol += strTime + strTmp;
			
		SetWindowText(m_strProtocol);
		UpdateData(FALSE);
	}

}

void CTaskManagerView::OnJobOk() 
{
	// TODO: Add your command handler code here
	
	::JobOk(m_nCurrJob);

	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format("%A %B %d %Y %H %M %S");
	CString strTmp;
	strTmp.Format(" Job N %d : OK \r\n", m_nCurrJob); 
	m_strProtocol += strTime + strTmp;
	
	SetWindowText(m_strProtocol);
	UpdateData(FALSE);

	m_nCurrJob = 0;

}

void CTaskManagerView::OnJobPause() 
{
	// TODO: Add your command handler code here

	
	CReasonDlg dlg;
	if(dlg.DoModal() == IDOK)
	{
		LRESULT lRes = ::Pause(m_nCurrJob, dlg.m_strReason);
		
		CTime t = CTime::GetCurrentTime();
		CString strTime = t.Format("%A %B %d %Y %H %M %S");
		CString strTmp;
		strTmp.Format(" Job N  %d ist angehalten.\r\n", m_nCurrJob); 
		m_strProtocol += strTime + strTmp;
		m_strProtocol += CString("Ursache: ") + dlg.m_strReason + CString("\r\n");

		if(lRes > 0)
		{
			m_nCurrJob = (UINT)lRes;
			strTmp.Format("Neu Job:  N  %d \r\n", (UINT)m_nCurrJob);
			m_strProtocol += strTmp;
		}	
		SetWindowText(m_strProtocol);
		UpdateData(FALSE);
		
	}

}
/*

HWND CTaskManagerView::FindJobAllocWnd()
{
	//= Suchen des Fenster der Anwendung JobAllocMsg.
	//= Die Anwendung muﬂ vorher das Suchen gestartet werden.

	HWND hWnd = ::FindWindow(NULL, "Unbenannt - JobAllocMsg");
	if(hWnd != NULL)
		TRACE("Fenster gefunden\n");
	else
		AfxMessageBox("Fenster der Anwendung JobAllocMsg nicht gefunden");

	return hWnd;

}

*/