// DCOMShareObj.cpp : Implementation of CDCOMShareObj
#include "stdafx.h"
#include "DCOMShareServer.h"
#include "DCOMShareObj.h"
#include <process.h>

/////////////////////////////////////////////////////////////////////////////
// CDCOMShareObj

enum STATE
{
	no_activ_obj,
	wait,
	busy,
	released
} g_state = no_activ_obj;
STATE g_state_old = g_state;

long g_lLastTrans = 0;


#define BUSY_SLEEP_MSK 5000
#define TRY_UPDATE_MSK 3000
#define MAX_SVR_COUNT 100
CDCOMShareObj* g_SvrArray[MAX_SVR_COUNT];

HANDLE CDCOMShareObj::m_hThread = NULL;
CComCriticalSection CDCOMShareObj::m_critsec;

void CDCOMShareObj::InitObj()
{
	if(g_state == no_activ_obj)
		InitGlobalData();

	m_iMyNumber = -1;

	m_critsec.Lock();

	for(int i = 0; i < MAX_SVR_COUNT; i++)
	{
		if(g_SvrArray[i] == NULL)
		{
			g_SvrArray[i] = this;
			m_iMyNumber = i;
			break;
		}
	}

	m_critsec.Unlock();

}

void CDCOMShareObj::InitGlobalData()
{
	// TODO: Add your implementation code here

	m_critsec.Init();
	m_critsec.Lock();

	for(int i = 0; i < MAX_SVR_COUNT; i++)
		g_SvrArray[i] = NULL;

	unsigned uThreadID;
	m_hThread = (HANDLE) _beginthreadex(NULL, 0, DoLoop, NULL, 0, &uThreadID);
	if(m_hThread == 0)
		return;

	g_state = g_state_old = wait;
	m_critsec.Unlock();

}

void CDCOMShareObj::FinalRelease()
{
	if(m_iMyNumber < 0)
		return;

	g_SvrArray[m_iMyNumber] = NULL;

	for(int i = 0; i < MAX_SVR_COUNT; i++)
	{
		if(g_SvrArray[i] != NULL)
			return;
	}

	//== Alle Objekte sind gelöscht

	g_state = released;
	::WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
	g_state_old = g_state = no_activ_obj;
}

STDMETHODIMP CDCOMShareObj::AddValue()
{
	// TODO: Add your implementation code here
	
	m_critsec.Lock();
	if(g_state != wait)
	{
		m_critsec.Unlock();
		return E_FAIL;
	}

	g_state = busy;
	m_critsec.Unlock();

	Sleep(BUSY_SLEEP_MSK);

	m_critsec.Lock();
	g_lLastTrans++;
	g_state = wait;
	m_critsec.Unlock();

	return S_OK;
}


unsigned int _stdcall CDCOMShareObj::DoLoop(void* p)
{
	while(TRUE)
	{
		if(g_state == released)
		{
			_endthreadex(0);
			return 0;
		}
		
		::Sleep(TRY_UPDATE_MSK);

		if(g_state != g_state_old)
		{
			g_state_old = g_state;

			long lVal = g_lLastTrans;
			if(g_state == busy)
				lVal = -1;
		
			for(int i = 0; i < MAX_SVR_COUNT; i++)
			{
				if(g_SvrArray[i] != NULL)
				{
					g_SvrArray[i]->UpdateState(lVal);
				}
			}
		}

	}

	return 0;
}

void CDCOMShareObj::UpdateState(long lVal)
{
	//== IConnectionPointImpl::m_vec verwaltet die Kommunikationspunkte

	IUnknown** ppUnk = m_vec.begin();

	if(*ppUnk != NULL)
	{
		IDCOMShareEvents* pEvents = (IDCOMShareEvents*)*ppUnk;
		pEvents->UpdateState(lVal); 
	}
}