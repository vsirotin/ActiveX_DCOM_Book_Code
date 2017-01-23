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

//-----------------------------------
//extern "C" __declspec(dllexport) int Test1();
__declspec(dllexport) int Test1();

int Test1()
{
	return 10;
}

//------------------------------------


//double WINAPI Test(double dVal)
//extern "C" __declspec(dllexport) double Test(double dVal) // EP
//double WINAPI Test(double dVal) //EP 
__declspec(dllexport) double Test(double dVal) 
//int Test(int iVal)
{
	return dVal + 10;
}

//-----------------------------------------------

CJobAllocManager g_JobAllocManager;

extern "C" __declspec(dllexport) LRESULT Pause(UINT nJob, CString strReason)
{
	return g_JobAllocManager.Pause(nJob, strReason);
}

extern "C" __declspec(dllexport) LRESULT NewJob(CString strUserName)
{
	return g_JobAllocManager.NewJob(strUserName);
}

extern "C" __declspec(dllexport) void JobOk(UINT nJob)
{
	g_JobAllocManager.JobOk(nJob);
}


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
