// JobAllocator.cpp : implementation file
//

#include "stdafx.h"
#include "JobAllocCOMDLL.h"
#include "JobAllocInterfaces.h"
#include "JobAllocator.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobAllocator


IMPLEMENT_DYNCREATE(CJobAllocator, CCmdTarget)

CJobAllocator::CJobAllocator()
{
	m_iCurrJob = 0;
	g_uObjCount++;
	m_bstrInfo = NULL;
}

CJobAllocator::~CJobAllocator()
{
	g_uObjCount--;
	if(m_bstrInfo != NULL)
		::SysFreeString(m_bstrInfo);

}


BEGIN_MESSAGE_MAP(CJobAllocator, CCmdTarget)
	//{{AFX_MSG_MAP(CJobAllocator)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CJobAllocator message handlers


BEGIN_INTERFACE_MAP(CJobAllocator, CCmdTarget)
	INTERFACE_PART(CJobAllocator, IID_IJobAlloc, JobAlloc)
	INTERFACE_PART(CJobAllocator, IID_IJobInfo, JobInfo)
END_INTERFACE_MAP();


// {65B121F0-A13B-11d1-A259-00A0C941DD59}
IMPLEMENT_OLECREATE(CJobAllocator, "Job Allocator", 
0x65b121f0, 0xa13b, 0x11d1, 0xa2, 0x59, 0x0, 0xa0, 0xc9, 0x41, 0xdd, 0x59);



STDMETHODIMP_(ULONG) CJobAllocator::XJobAlloc::AddRef()
{	
	METHOD_PROLOGUE(CJobAllocator, JobAlloc)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CJobAllocator::XJobAlloc::Release()
{
	METHOD_PROLOGUE(CJobAllocator, JobAlloc)
	return pThis->ExternalRelease();
}

STDMETHODIMP CJobAllocator::XJobAlloc::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE(CJobAllocator, JobAlloc)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

STDMETHODIMP_(int&) CJobAllocator::XJobAlloc::Pause(int nJob, BSTR bstrReason)
{
	METHOD_PROLOGUE(CJobAllocator, JobAlloc)

	CString strReason(bstrReason);
  
	pThis->m_iCurrJob++;
	TRACE("Pause bei Aufgabe %d. Ursache %s. Neue Aufgabe: %d\n", 
			nJob, strReason, pThis->m_iCurrJob);
	
	return pThis->m_iCurrJob;

}


STDMETHODIMP_(int&) CJobAllocator::XJobAlloc::NewJob(BSTR bstrUserName)
{
	METHOD_PROLOGUE(CJobAllocator, JobAlloc)

	CString strUserName(bstrUserName);
	
	pThis->m_iCurrJob++;
	TRACE("Neue Aufgabe N %d für %s \n", pThis->m_iCurrJob, strUserName);
	return pThis->m_iCurrJob;
}

STDMETHODIMP CJobAllocator::XJobAlloc::JobOk(int nJob)
{
	TRACE("Aufgabe %d OK\n", nJob);
	return true;
}


////////////////////////////////////////////////////////////////////////
// JobInfo

STDMETHODIMP_(ULONG) CJobAllocator::XJobInfo::AddRef()
{	
	METHOD_PROLOGUE(CJobAllocator, JobInfo)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CJobAllocator::XJobInfo::Release()
{
	METHOD_PROLOGUE(CJobAllocator, JobInfo)
	return pThis->ExternalRelease();
}

STDMETHODIMP CJobAllocator::XJobInfo::QueryInterface(REFIID iid, LPVOID* ppvObj)
{
	METHOD_PROLOGUE(CJobAllocator, JobInfo)
	return pThis->ExternalQueryInterface(&iid, ppvObj);
}

#define MAX_STRING_LENGTH 100
STDMETHODIMP_(BSTR&) CJobAllocator::XJobInfo::GetInfo(int nJob)
{
	METHOD_PROLOGUE(CJobAllocator, JobInfo)
	
	CString strInfo;
	strInfo.Format("Info zur Aufgabe %d", nJob);

	pThis->m_bstrInfo = strInfo.AllocSysString();

	TRACE("GetInfo zur Aufgabe %d\n", nJob);
	
	return pThis->m_bstrInfo;

}
