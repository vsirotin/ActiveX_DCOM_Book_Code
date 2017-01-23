// ShareEvents.cpp: implementation of the CShareEvents class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ShareClient.h"
#include "DCOMShareServer.h"
#include "ShareClientDlg.h"
#include "ShareEvents.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

CShareEvents::CShareEvents()
{

}

STDMETHODIMP  CShareEvents::UpdateState(long lLastTran)
{

	CShareClientDlg* pDlg = (CShareClientDlg*)theApp.m_pMainWnd;
	ASSERT(pDlg);
	pDlg->UpdateState(lLastTran);

	return S_OK;
}