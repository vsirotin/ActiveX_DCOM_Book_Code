// AxDCommandLineInfo.cpp : implementation file
//

#include "stdafx.h"
#include "JobAlloc.h"
#include "AxDCommandLineInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


CAxDCommandLineInfo::CAxDCommandLineInfo()
{
}

CAxDCommandLineInfo::~CAxDCommandLineInfo()
{
}

/////////////////////////////////////////////////////////////////////////////
// CAxDCommandLineInfo message handlers

void CAxDCommandLineInfo::ParseParam( LPCTSTR lpszParam, BOOL bFlag, BOOL bLast )
{
//	static bool bFirstItem = true;

//	if(!bFirstItem)
		theApp.m_strName += CString(lpszParam) + CString(" ");
//	else
//		bFirstItem = false;

	CCommandLineInfo::ParseParam( lpszParam, bFlag, bLast );

};
