// JobAllocManager.cpp : implementation file
//

#include "stdafx.h"
#include "JobAllocManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CJobAllocManager


CJobAllocManager::CJobAllocManager()
{
	m_nCurrJob = 1;
}

CJobAllocManager::~CJobAllocManager()
{
}

LRESULT CJobAllocManager::Pause(UINT nJob, CString strReason)
{
	TRACE("Pause bei Aufgabe %d. Ursache %s. Neue Aufgabe: %d\n", 
		nJob, strReason, m_nCurrJob);

	return m_nCurrJob++;
}

LRESULT CJobAllocManager::NewJob(CString strUserName)
{
	TRACE("Neue Aufgabe N %d für %s \n", m_nCurrJob, strUserName);
	return m_nCurrJob++;
}

void CJobAllocManager::JobOk(UINT nJob)
{
	TRACE("Aufgabe %d OK\n", nJob);
}


/////////////////////////////////////////////////////////////////////////////
// CJobAllocManager message handlers
