// TaskManagerCOMView.cpp : implementation of the CTaskManagerCOMView class
//

#include "stdafx.h"
#include "TaskManagerCOM.h"

#include "TaskManagerCOMDoc.h"
#include "TaskManagerCOMView.h"

#include "C:\VCPP\AxD\Kap3\JobAllocCOMDLL\JobAllocInterfaces.h"

#include "ReasonDlg1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView

IMPLEMENT_DYNCREATE(CTaskManagerCOMView, CEditView)

BEGIN_MESSAGE_MAP(CTaskManagerCOMView, CEditView)
	//{{AFX_MSG_MAP(CTaskManagerCOMView)
	ON_COMMAND(ID_JOB_NEW, OnJobNew)
	ON_COMMAND(ID_JOB_PAUSE, OnJobPause)
	ON_COMMAND(ID_JOB_OK, OnJobOk)
	ON_COMMAND(ID_JOB_GET_INFO, OnJobGetInfo)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CEditView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CEditView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView construction/destruction

CTaskManagerCOMView::CTaskManagerCOMView()
{
	// TODO: add construction code here
	m_pIJobAlloc = NULL;
	m_pIJobInfo = NULL;
	m_bstrUserName = NULL;
	m_nCurrJob = 0;
}

CTaskManagerCOMView::~CTaskManagerCOMView()
{
	if(m_pIJobAlloc != NULL)
	{
		m_pIJobAlloc->Release();

	}

	if(m_pIJobInfo != NULL)
	{
		m_pIJobInfo->Release();

	}

	if(m_bstrUserName != NULL)
	{
		::SysFreeString(m_bstrUserName);
	}

}

BOOL CTaskManagerCOMView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	BOOL bPreCreated = CEditView::PreCreateWindow(cs);
	cs.style &= ~(ES_AUTOHSCROLL|WS_HSCROLL);	// Enable word-wrapping

	return bPreCreated;
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView drawing

void CTaskManagerCOMView::OnDraw(CDC* pDC)
{
	CTaskManagerCOMDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView printing

BOOL CTaskManagerCOMView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default CEditView preparation
	return CEditView::OnPreparePrinting(pInfo);
}

void CTaskManagerCOMView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView begin printing.
	CEditView::OnBeginPrinting(pDC, pInfo);
}

void CTaskManagerCOMView::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// Default CEditView end printing
	CEditView::OnEndPrinting(pDC, pInfo);
}

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView diagnostics

#ifdef _DEBUG
void CTaskManagerCOMView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTaskManagerCOMView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}

CTaskManagerCOMDoc* CTaskManagerCOMView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTaskManagerCOMDoc)));
	return (CTaskManagerCOMDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTaskManagerCOMView message handlers

void CTaskManagerCOMView::OnJobNew() 
{
	// TODO: Add your command handler code here

	SetJobAllocObj();
	m_nCurrJob = m_pIJobAlloc->NewJob(m_bstrUserName);

	//== Ausgabe in Sicht
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format("%A %B %d %Y %H %M %S");
	CString strTmp;
	strTmp.Format(" Neue Job N %d\r\n", m_nCurrJob); 
	m_strProtocol += strTime + strTmp;
				
	SetWindowText(m_strProtocol);
	UpdateData(FALSE);

}

void CTaskManagerCOMView::OnJobPause() 
{
	// TODO: Add your command handler code here

	CReasonDlg dlg;
	if(dlg.DoModal() != IDOK)
		return;

	BSTR bstrReason = dlg.m_strReason.AllocSysString();

	SetJobAllocObj();
	UINT nCurrJob = m_pIJobAlloc->Pause(m_nCurrJob, bstrReason);

	::SysFreeString(bstrReason);

	//== Ausgabe in Sicht
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format("%A %B %d %Y %H %M %S");
	CString strTmp;
	
	strTmp.Format(" Job N  %d ist angehalten.\r\n", m_nCurrJob); 
	m_strProtocol += strTime + strTmp;
	m_strProtocol += CString("Ursache: ") + dlg.m_strReason + CString("\r\n");

	m_nCurrJob = nCurrJob;
	strTmp.Format("Neu Job:  N  %d \r\n", m_nCurrJob);
	m_strProtocol += strTmp;

	SetWindowText(m_strProtocol);
	UpdateData(FALSE);
			
}

void CTaskManagerCOMView::OnJobOk() 
{
	// TODO: Add your command handler code here
	SetJobAllocObj();
	m_pIJobAlloc->JobOk(m_nCurrJob);

	//== Ausgabe in Sicht
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format("%A %B %d %Y %H %M %S");
	CString strTmp;
	strTmp.Format(" Job N %d : OK \r\n", m_nCurrJob); 
	m_strProtocol += strTime + strTmp;
		
	SetWindowText(m_strProtocol);
	UpdateData(FALSE);
	
}

void CTaskManagerCOMView::SetJobAllocObj()
{
	
	if(m_pIJobAlloc != NULL)
		return;         //== Objekt ist festgelegt

	CLSID clsid;
	LPCLASSFACTORY pClf;
	LPUNKNOWN pUnk;

	HRESULT hr;
	if((hr = ::CLSIDFromProgID(L"Job Allocator", &clsid) != NOERROR))
	{
		TRACE("Fehler bei CLSIDFromProgID\n");
		return;
	}

	hr = ::CoGetClassObject(clsid, CLSCTX_INPROC_SERVER,
		NULL, IID_IClassFactory, (void**)&pClf);

	if(hr != NOERROR)
	{
		TRACE("Fehler bei CoGetClassObject\n");
		return;
	}

	pClf->CreateInstance(NULL, IID_IUnknown, (void**)&pUnk);
	
	pUnk->QueryInterface(IID_IJobAlloc, (void**)&m_pIJobAlloc);
	ASSERT(m_pIJobAlloc);

	pUnk->QueryInterface(IID_IJobInfo, (void**)&m_pIJobInfo);
	ASSERT(m_pIJobInfo);

	pClf->Release();
	pUnk->Release();

	SetUseName();

}

#define MAX_SIZE_USER_NAME 100
void CTaskManagerCOMView::SetUseName()
{
	if(m_bstrUserName == NULL)
	{
		char  cUserName[MAX_SIZE_USER_NAME];
		DWORD dwNameLen = MAX_SIZE_USER_NAME;

		::GetUserName(cUserName, &dwNameLen);
		CString strUserName(cUserName);
		m_bstrUserName = strUserName.AllocSysString();
	}
}
	
void CTaskManagerCOMView::OnJobGetInfo() 
{
	// TODO: Add your command handler code here
	SetJobAllocObj();
	BSTR bstrInfo = m_pIJobInfo->GetInfo(m_nCurrJob);

	CString strInfo(bstrInfo);

	//== Ausgabe in Sicht
	CTime t = CTime::GetCurrentTime();
	CString strTime = t.Format("%A %B %d %Y %H %M %S");
	CString strTmp;
	strTmp.Format(" Info: "); 
	m_strProtocol += strTime + strTmp;
	m_strProtocol += strInfo + CString("\r\n");
	
	SetWindowText(m_strProtocol);
	UpdateData(FALSE);
}
